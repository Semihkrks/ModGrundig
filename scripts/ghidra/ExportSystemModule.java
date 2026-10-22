// Local static research only. Does not patch, export, or execute target bytes.
// @category Grundig
import ghidra.app.util.headless.HeadlessScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.lang.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.io.*;
import java.nio.file.*;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Pattern;

public class ExportSystemModule extends HeadlessScript {
    private final Gson gson = new GsonBuilder().disableHtmlEscaping().create();
    private void row(Writer w,Object value) throws Exception { gson.toJson(value,w); w.write("\n"); }
    private String addr(Address a) { return a.toString(); }
    @Override public void run() throws Exception {
        Path root = Paths.get(getScriptArgs()[0]);
        String sha = currentProgram.getExecutableSHA256();
        if (sha==null || !sha.matches("[a-fA-F0-9]{64}")) throw new IllegalStateException("No target hash");
        Path out = root.resolve(sha.toLowerCase());
        Files.createDirectories(out);
        FunctionManager fm = currentProgram.getFunctionManager();
        ReferenceManager rm = currentProgram.getReferenceManager();
        long functions=0, refs=0, callrefs=0, symbols=0, computed=0;
        List<Function> candidates = new ArrayList<>();
        Pattern priority = Pattern.compile("(?i)(volume|mute|cec|remote|keyhandler|tuner|channel|power|standby|update|upgrade|verify|signature|dlopen|dlsym|mount|init|render|surface|font|resource|animation|network|socket|storage|usb|nand|flash)");
        try (Writer fw=Files.newBufferedWriter(out.resolve("functions.jsonl"));
             Writer sw=Files.newBufferedWriter(out.resolve("symbols.jsonl"));
             Writer rw=Files.newBufferedWriter(out.resolve("xrefs.jsonl"));
             Writer cw=Files.newBufferedWriter(out.resolve("computed-calls.jsonl"))) {
            for (Function f:fm.getFunctions(true)) {
                Map<String,Object> r=new LinkedHashMap<>();
                r.put("address",addr(f.getEntryPoint())); r.put("name",f.getName(true));
                r.put("signature",f.getSignature().toString()); r.put("body_bytes",f.getBody().getNumAddresses());
                r.put("external",f.isExternal()); r.put("thunk",f.isThunk());
                row(fw,r); functions++;
                if (!f.isExternal() && !f.isThunk() && f.getBody().getNumAddresses()>=12 &&
                    f.getBody().getNumAddresses()<=8192 && priority.matcher(f.getName(true)).find()) candidates.add(f);
            }
            for (Symbol s:currentProgram.getSymbolTable().getAllSymbols(true)) {
                row(sw,Map.of("address",addr(s.getAddress()),"name",s.getName(true),
                              "type",s.getSymbolType().toString(),"source",s.getSource().toString())); symbols++;
            }
            ReferenceIterator it=rm.getReferenceIterator(currentProgram.getAddressFactory().getDefaultAddressSpace().getMinAddress());
            while (it.hasNext() && !monitor.isCancelled()) {
                Reference ref=it.next(); Function from=fm.getFunctionContaining(ref.getFromAddress());
                Map<String,Object> r=new LinkedHashMap<>();
                r.put("from",addr(ref.getFromAddress())); r.put("to",addr(ref.getToAddress()));
                r.put("type",ref.getReferenceType().toString()); r.put("source",ref.getSource().toString());
                r.put("call",ref.getReferenceType().isCall());
                if (from!=null) r.put("function",addr(from.getEntryPoint()));
                row(rw,r); refs++; if(ref.getReferenceType().isCall())callrefs++;
            }
            for (Instruction instruction:currentProgram.getListing().getInstructions(true)) {
                if(instruction.getFlowType().isCall() && instruction.getFlowType().isComputed()) {
                    Map<String,Object> r=new LinkedHashMap<>(); r.put("site",addr(instruction.getAddress()));
                    r.put("instruction",instruction.toString());
                    Function f=fm.getFunctionContaining(instruction.getAddress());
                    if(f!=null)r.put("function",addr(f.getEntryPoint()));
                    r.put("analyzed_destinations",Arrays.stream(instruction.getFlows()).map(a->addr(a)).toList());
                    row(cw,r); computed++;
                }
            }
        }
        // Small initial samples. Semantic interpretation is a separate measured phase.
        candidates.sort(Comparator.comparingLong(f->f.getBody().getNumAddresses()));
        DecompInterface decompiler=new DecompInterface();
        int attempted=0, complete=0; List<Map<String,Object>> decomp=new ArrayList<>();
        Register t9=currentProgram.getRegister("t9");
        for(Function f:candidates.subList(0,Math.min(6,candidates.size()))) {
            if(t9!=null) currentProgram.getProgramContext().setRegisterValue(
                f.getEntryPoint(),f.getEntryPoint(),new RegisterValue(t9,BigInteger.valueOf(f.getEntryPoint().getOffset())));
        }
        decompiler.openProgram(currentProgram);
        try {
            for(Function f:candidates.subList(0,Math.min(6,candidates.size()))) {
                attempted++; DecompileResults result=decompiler.decompileFunction(f,8,monitor);
                Map<String,Object> r=new LinkedHashMap<>();r.put("address",addr(f.getEntryPoint()));r.put("name",f.getName(true));
                r.put("complete",result.decompileCompleted());r.put("error",result.getErrorMessage());
                if(result.decompileCompleted() && result.getDecompiledFunction()!=null) {
                    Files.writeString(out.resolve(addr(f.getEntryPoint())+".c"),result.getDecompiledFunction().getC()); complete++;
                }
                decomp.add(r);
            }
        } finally {decompiler.dispose();}
        Map<String,Object> summary=new LinkedHashMap<>();
        summary.put("program",currentProgram.getName());summary.put("sha256",sha);
        summary.put("language",currentProgram.getLanguageID().toString());
        summary.put("functions",functions);summary.put("symbols",symbols);summary.put("xrefs",refs);
        summary.put("analyzed_call_xrefs",callrefs);summary.put("computed_call_instructions",computed);
        summary.put("analysis_timeout",analysisTimeoutOccurred());
        summary.put("sample_decompile_attempted",attempted);summary.put("sample_decompile_complete",complete);
        summary.put("samples",decomp);summary.put("firmware_executed",false);summary.put("firmware_bytes_modified",false);
        summary.put("evidence_kind","direct_Ghidra_static_analysis_not_REA_Evidence");
        summary.put("limitations",List.of("MIPS constant analyzer disabled; indirect references and function discovery can be incomplete.",
            "8-second decompile samples are selected by name and size, not established critical-function coverage.",
            "t9=entry is an explicit PIC analysis assumption in newly created analysis databases.",
            "Decompiler prototypes, runtime bindings, vtable dispatch and device state are unverified.",
            "No original source recovery or runtime execution is claimed."));
        Files.writeString(out.resolve("summary.json"),new GsonBuilder().setPrettyPrinting().create().toJson(summary));
        println("MODULE_EXPORT "+sha+" functions="+functions+" refs="+refs+" decompiled="+complete+"/"+attempted);
    }
}
