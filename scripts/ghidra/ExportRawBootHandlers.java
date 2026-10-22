// Offline raw boot investigation. Only the newly imported analysis DB is annotated.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.io.*;
import java.util.*;
import java.security.MessageDigest;
import com.google.gson.JsonParser;

public class ExportRawBootHandlers extends GhidraScript {
    private static final long BASE=0x8e1efd80L, SIZE=2078028L;
    private static final String[] NAMES={"filepartload","mscompress7","crc32","ncishash","ncisbl"};
    private static final long[] TABLE={0x1fa20c,0x1fa3cc,0x1faebc,0x1fb098,0x1fb0b4};
    private static final long[] HANDLER={0x238a8,0x25f00,0x5684c,0x5b4ac,0x5a750};
    private final com.google.gson.Gson gson=new GsonBuilder().setPrettyPrinting().disableHtmlEscaping().create();
    private Address at(long off){return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(BASE+off);}
    private long off(Address a){return a.getOffset()-BASE;}
    private String hex(long n){return String.format("0x%x",n);}
    private long word(Address a)throws Exception{return Integer.toUnsignedLong(currentProgram.getMemory().getInt(a));}
    private boolean backed(Address a){return a.getOffset()>=BASE && a.getOffset()<BASE+SIZE && currentProgram.getMemory().contains(a);}
    private String textAt(long va)throws Exception{
        StringBuilder s=new StringBuilder();Address a=at(va-BASE);
        for(int n=0;n<2048 && backed(a.add(n));n++){int c=Byte.toUnsignedInt(currentProgram.getMemory().getByte(a.add(n)));if(c==0)return s.toString();if(c<32 && c!=9 && c!=10 && c!=13)throw new IllegalStateException("Nontext diagnostic");s.append((char)c);}
        throw new IllegalStateException("Unterminated diagnostic");
    }
    private void row(Writer w,Object r)throws Exception{w.write(new com.google.gson.Gson().toJson(r));w.write("\n");}
    @Override public void run()throws Exception{
        Path out=Paths.get(getScriptArgs()[0]);Files.createDirectories(out);
        byte[] manifestBytes=Files.readAllBytes(out.resolve("source-hash-manifest.json"));
        String expectedHash=JsonParser.parseString(new String(manifestBytes,java.nio.charset.StandardCharsets.UTF_8)).getAsJsonObject().getAsJsonArray("inputs").get(0).getAsJsonObject().get("sha256").getAsString();
        if(!expectedHash.equalsIgnoreCase(currentProgram.getExecutableSHA256()))throw new IllegalStateException("DB source hash mismatch");
        if(currentProgram.getMemory().getMinAddress().getOffset()!=BASE)throw new IllegalStateException("Unexpected raw block start: "+currentProgram.getMemory().getMinAddress());
        if(currentProgram.getMemory().getSize()!=SIZE)throw new IllegalStateException("Unexpected source size");
        List<Map<String,Object>> blocks=new ArrayList<>();
        for(MemoryBlock b:currentProgram.getMemory().getBlocks()){
            b.setExecute(true); // Explicit raw import analysis assumption, not observed loader permissions.
            blocks.add(Map.of("start",b.getStart().toString(),"end",b.getEnd().toString(),"bytes",b.getSize(),"execute_assumed",true));
        }
        List<Map<String,Object>> entries=new ArrayList<>();List<Function> handlers=new ArrayList<>();
        for(int i=0;i<NAMES.length;i++){
            Address table=at(TABLE[i]),entry=at(HANDLER[i]);
            if((entry.getOffset()&3)!=0 || !backed(entry) || !currentProgram.getMemory().getBlock(entry).isExecute())throw new IllegalStateException("Invalid entry");
            if(word(table.add(12))!=entry.getOffset())throw new IllegalStateException("Command pointer mismatch: "+NAMES[i]);
            List<String> words=new ArrayList<>();for(int j=0;j<6;j++)words.add(hex(word(table.add(j*4))));
            for(int field:new int[]{0,12,16,20}){
                Address p=table.add(field);long target=word(p);
                if(getDataAt(p)==null)createData(p,PointerDataType.dataType);
                if(field!=12 && target>=BASE && target<BASE+SIZE){
                    Address s=at(target-BASE);if(getDataAt(s)==null)createAsciiString(s);
                }
            }
            if(getDataAt(table.add(4))==null)createDWord(table.add(4));if(getDataAt(table.add(8))==null)createDWord(table.add(8));
            String command=getDataAt(at(word(table)-BASE)).getValue().toString();
            if(!command.equals(NAMES[i]))throw new IllegalStateException("Command name mismatch");
            // Restrict recursive branch discovery to 8 KiB per selected handler; no whole-image analysis.
            AddressSet region=new AddressSet(entry,at(Math.min(SIZE-1,HANDLER[i]+8191)));
            DisassembleCommand dis=new DisassembleCommand(entry,region,true);dis.enableCodeAnalysis(false);
            boolean decoded=dis.applyTo(currentProgram,monitor);
            Function f=createFunction(entry,"candidate_cmd_"+NAMES[i]);
            if(f==null)f=getFunctionAt(entry);
            Map<String,Object> e=new LinkedHashMap<>();e.put("command",NAMES[i]);e.put("table_file_offset",hex(TABLE[i]));
            e.put("record_u32le",words);e.put("entry_file_offset",hex(HANDLER[i]));e.put("candidate_va",entry.toString());
            e.put("usage",textAt(word(table.add(16))));e.put("help",textAt(word(table.add(20))));
            e.put("disassemble_result",decoded);e.put("function_created",f!=null);e.put("disassembly_window_bytes",8192);
            if(f!=null){handlers.add(f);e.put("body_bytes",f.getBody().getNumAddresses());}
            entries.add(e);
        }
        long instructions=0,calls=0,refs=0;
        try(Writer iw=Files.newBufferedWriter(out.resolve("handler-instructions.jsonl"));Writer rw=Files.newBufferedWriter(out.resolve("handler-xrefs.jsonl"))){
            for(Function f:handlers){
                for(Instruction ins:currentProgram.getListing().getInstructions(f.getBody(),true)){
                    row(iw,Map.of("handler",f.getName(),"candidate_va",ins.getAddress().toString(),"file_offset",hex(off(ins.getAddress())),"instruction",ins.toString()));instructions++;
                    for(Reference r:ins.getReferencesFrom()){
                        Map<String,Object> x=new LinkedHashMap<>();x.put("handler",f.getName());x.put("from",r.getFromAddress().toString());
                        x.put("to",r.getToAddress().toString());x.put("type",r.getReferenceType().toString());x.put("source",r.getSource().toString());
                        if(backed(r.getToAddress()))x.put("target_file_offset",hex(off(r.getToAddress())));
                        row(rw,x);refs++;if(r.getReferenceType().isCall())calls++;
                    }
                }
            }
        }
        DecompInterface dec=new DecompInterface();List<Map<String,Object>> decomp=new ArrayList<>();int complete=0;
        dec.openProgram(currentProgram);
        try{for(Function f:handlers){
            DecompileResults r=dec.decompileFunction(f,30,monitor);Map<String,Object> d=new LinkedHashMap<>();
            d.put("command",f.getName());d.put("candidate_va",f.getEntryPoint().toString());d.put("complete",r.decompileCompleted());d.put("error",r.getErrorMessage());
            if(r.decompileCompleted() && r.getDecompiledFunction()!=null){Files.writeString(out.resolve(f.getName()+".c"),r.getDecompiledFunction().getC());complete++;}
            decomp.add(d);
        }}finally{dec.dispose();}
        Map<String,Object> summary=new LinkedHashMap<>();summary.put("source_sha256",currentProgram.getExecutableSHA256());
        summary.put("source_bytes",SIZE);summary.put("language",currentProgram.getLanguageID().toString());summary.put("compiler_spec",currentProgram.getCompilerSpec().getCompilerSpecID().toString());
        summary.put("source_manifest_sha256",java.util.HexFormat.of().formatHex(MessageDigest.getInstance("SHA-256").digest(manifestBytes)));
        summary.put("candidate_va_minus_file_offset",hex(BASE));summary.put("program_image_base_metadata",currentProgram.getImageBase().toString());summary.put("memory_blocks",blocks);summary.put("commands",entries);
        summary.put("selected_handlers",handlers.size());summary.put("instruction_count",instructions);summary.put("xref_count",refs);summary.put("call_xref_count",calls);
        summary.put("decompile_attempted",handlers.size());summary.put("decompile_complete",complete);summary.put("decompiles",decomp);
        summary.put("firmware_executed",false);summary.put("firmware_bytes_modified",false);summary.put("evidence_kind","direct_Ghidra_static_analysis_not_REA_Evidence");
        summary.put("context_assumptions",List.of("Raw BinaryLoader image base 0x8e1efd80 is a command-pointer-derived candidate, not device loader evidence.","MIPS:LE:32:default, default compiler spec; raw memory marked executable only in this new analysis DB.","No whole-program auto-analysis; branch disassembly restricted to 8 KiB per handler; helper functions are not discovered or decompiled.","No gp/t9 values forced; decompiler types/prototypes and unresolved helper names are inferred, not source symbols.","Function boundaries, indirect calls, absolute data references and coverage may be incomplete; no runtime acceptance or signature behavior follows from command names."));
        Files.writeString(out.resolve("summary.json"),gson.toJson(summary));
        // Explicit diagnostics selected from these command bodies; no broad strings dump.
        List<Map<String,Object>> diagnostics=new ArrayList<>();
        for(long va:new long[]{0x8e3a1d8cL,0x8e3a1dbcL,0x8e3a1dd4L,0x8e3a1de4L,0x8e3a1e00L,0x8e3a1e44L,0x8e3a1e88L,0x8e3a1e9cL,0x8e3a1ee0L,0x8e3a1efcL,0x8e3a1f0cL,0x8e3a1f1cL,0x8e3a1f2cL,0x8e3a1f40L,0x8e3a20c0L,0x8e3a20dcL,0x8e3a20f8L,0x8e3a2114L,0x8e3a2134L,0x8e3a2150L,0x8e3a2170L}){
            diagnostics.add(Map.of("candidate_va",hex(va),"file_offset",hex(va-BASE),"text",textAt(va)));
        }
        Files.writeString(out.resolve("referenced-diagnostics.json"),gson.toJson(diagnostics));
        println("BOOT_CANDIDATE_EXPORT handlers="+handlers.size()+" instructions="+instructions+" refs="+refs+" decompiled="+complete+"/"+handlers.size());
    }
}
