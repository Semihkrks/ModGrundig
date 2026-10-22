// Bounded, unsaved callback recovery. Wrapper MUST use -readOnly -noanalysis.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class ExportDirectFbCallbacks extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("Expected selection and fresh output directory");
        Path selection = Paths.get(args[0]), output = Paths.get(args[1]);
        JsonObject config = JsonParser.parseString(Files.readString(selection)).getAsJsonObject();
        if (!config.get("target_sha256").getAsString().equalsIgnoreCase(currentProgram.getExecutableSHA256())) throw new IllegalStateException("Program identity mismatch");
        JsonObject bounds = config.getAsJsonObject("function_bounds");
        List<Map<String,Object>> recovery = new ArrayList<>();
        FunctionManager fm = currentProgram.getFunctionManager();
        for (JsonElement selector : config.getAsJsonArray("addresses")) {
            monitor.checkCancelled();
            String key = selector.getAsString();
            Address entry = toAddr(key), end = toAddr(bounds.getAsJsonObject(key).get("end_exclusive").getAsString()).subtract(1);
            AddressSet range = new AddressSet(entry, end);
            MemoryBlock block = currentProgram.getMemory().getBlock(entry);
            if (block == null || !block.isExecute() || !block.isInitialized() || !block.contains(end) || entry.getOffset()%4!=0 || (end.getOffset()+1)%4!=0 || range.getNumAddresses()>16384) throw new IllegalStateException("Invalid bounded executable range " + key);
            Map<String,Object> row = new LinkedHashMap<>();
            row.put("entry", key); row.put("end_inclusive", end.toString()); row.put("bound_basis", bounds.get(key));
            row.put("executable_initialized_block",block.getName());
            Function existing = fm.getFunctionAt(entry);
            row.put("exact_function_before",existing==null?null:existing.getName());
            List<String> conflicts = new ArrayList<>();
            Iterator<Function> it = fm.getFunctionsOverlapping(range);
            while(it.hasNext()) { Function f=it.next(); conflicts.add(f.getEntryPoint()+":"+f.getName()+":"+f.getBody()); }
            row.put("overlapping_functions_before",conflicts);
            // Every change is ephemeral because analyzeHeadless is readOnly.
            for (String conflict:conflicts) fm.removeFunction(toAddr(conflict.split(":",2)[0]));
            clearListing(entry,end);
            DisassembleCommand command = new DisassembleCommand(entry,range,true);
            boolean ok = command.applyTo(currentProgram,monitor);
            row.put("disassemble_success",ok); row.put("disassemble_status",command.getStatusMsg());
            List<String> missing = new ArrayList<>();
            for (Address a=entry; a.compareTo(end)<=0; a=a.add(4)) if(currentProgram.getListing().getInstructionAt(a)==null) missing.add(a.toString());
            row.put("undisassembled_word_addresses",missing);
            Function f = fm.createFunction("callback_"+key,entry,range,SourceType.ANALYSIS);
            if(f==null) throw new IllegalStateException("Could not create callback "+key);
            StringBuilder asm = new StringBuilder("; Direct Ghidra static disassembly. Unsaved bounded callback metadata.\n");
            InstructionIterator instructions = currentProgram.getListing().getInstructions(range,true);
            List<Map<String,Object>> transfers = new ArrayList<>();
            while(instructions.hasNext()) {
                Instruction ins=instructions.next();
                asm.append(ins.getAddress()).append("  ").append(ins).append("\n");
                if(ins.getFlowType().isCall() || ins.getFlowType().isJump() || ins.getFlowType().isTerminal()) {
                    Map<String,Object> transfer=new LinkedHashMap<>();transfer.put("address",ins.getAddress().toString());transfer.put("assembly",ins.toString());transfer.put("flow_type",ins.getFlowType().toString());
                    List<String> flows=new ArrayList<>();for(Address dest:ins.getFlows()) flows.add(dest.toString());transfer.put("flows",flows);transfers.add(transfer);
                }
            }
            Files.writeString(output.resolve(key+".asm"),asm.toString(),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);
            Files.writeString(output.resolve(key+"-transfers.json"),new GsonBuilder().setPrettyPrinting().create().toJson(transfers),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);
            recovery.add(row);
        }
        Files.writeString(output.resolve("callback-recovery.json"),new GsonBuilder().serializeNulls().setPrettyPrinting().create().toJson(recovery),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);
        runScript("ExportUiSelection.java",new String[]{selection.toString(),output.toString()});
        Path summary=output.resolve("summary.json");JsonObject result=JsonParser.parseString(Files.readString(summary)).getAsJsonObject();
        result.addProperty("ephemeral_created_callback_count",recovery.size());result.addProperty("recovery_file","callback-recovery.json");
        result.addProperty("boundary_basis","Exact MIPS .pdr procedure entry and next .pdr entry, corroborated by constructor pointer and assembly PIC prologue; contiguous body is an analysis assumption, not recovered source extent.");
        result.getAsJsonArray("limitations").add("This script first clears selected bounded code units, disassembles and creates functions in unsaved analysis metadata; original bytes and saved database are not written.");
        // Override inherited limitation that applies only to the delegated exporter.
        result.getAsJsonArray("limitations").remove(new JsonPrimitive("Only existing exact function entries are selected; no functions, instructions or data are created."));
        Files.writeString(summary,new GsonBuilder().serializeNulls().setPrettyPrinting().create().toJson(result),StandardCharsets.UTF_8);
    }
}
