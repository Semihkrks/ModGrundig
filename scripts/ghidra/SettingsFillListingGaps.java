// Metadata-only decoding of two proven MIPS switch-case ranges. Never executes target.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.JumpTable;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class SettingsFillListingGaps extends GhidraScript {
    private static final String SHA = "51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916";
    private int count(AddressSetView range) {
        int n=0;
        InstructionIterator it=currentProgram.getListing().getInstructions(range,true);
        while(it.hasNext()){ it.next(); n++; }
        return n;
    }
    public void run() throws Exception {
        if(getScriptArgs().length!=1)throw new IllegalArgumentException("output directory required");
        if(!SHA.equals(currentProgram.getExecutableSHA256()))throw new IllegalStateException("target digest mismatch");
        Path output=Path.of(getScriptArgs()[0]);
        if(!Files.isDirectory(output))throw new IllegalArgumentException("existing output directory required");
        List<Map<String,Object>> rows=new ArrayList<>();
        List<Map<String,Object>> switches=new ArrayList<>();
        long[][] gaps={{0x55e834L,0x55ead4L},{0x55f598L,0x55f838L}};
        int tx=currentProgram.startTransaction("Settings bounded metadata-only gap decode");
        boolean success=false;
        try {
            for(long[] bounds:gaps){
                Address start=toAddr(bounds[0]),end=toAddr(bounds[1]-1);
                AddressSet range=new AddressSet(start,end);
                int before=count(range);
                // Each selected range is a verified 672-byte series of MIPS switch cases.
                // Restriction prevents following calls/branches outside the selected gap.
                boolean applied=true;
                List<String> messages=new ArrayList<>();
                int seeds=0;
                // Individual case blocks branch out of the gap; seed remaining aligned
                // case instructions without clearing or modifying any existing code unit.
                for(long cursor=bounds[0];cursor<bounds[1];cursor+=4){
                    Address at=toAddr(cursor);
                    if(currentProgram.getListing().getInstructionAt(at)!=null)continue;
                    DisassembleCommand command=new DisassembleCommand(at,range,true);
                    command.enableCodeAnalysis(false);
                    applied=command.applyTo(currentProgram,monitor)&&applied;
                    if(command.getStatusMsg()!=null)messages.add(command.getStatusMsg());
                    seeds++;
                }
                int after=count(range);
                Map<String,Object> row=new LinkedHashMap<>();
                row.put("start",start.toString());row.put("end_exclusive",toAddr(bounds[1]).toString());
                row.put("instruction_count_before",before);row.put("instruction_count_after",after);
                row.put("expected_instruction_count",(bounds[1]-bounds[0])/4);
                row.put("command_applied",applied);row.put("status_messages",messages);row.put("aligned_seeds",seeds);
                rows.add(row);
                if(after!=(bounds[1]-bounds[0])/4)throw new IllegalStateException("incomplete restricted gap decoding: "+rows);
            }
            Function function=currentProgram.getFunctionManager().getFunctionAt(toAddr(0x55b6c0L));
            if(function==null)throw new IllegalStateException("selected function absent");
            long gp=0x10cc310L;
            long base=Integer.toUnsignedLong(currentProgram.getMemory().getInt(toAddr(gp-0x7fdcL)));
            if(base!=0xfe0000L)throw new IllegalStateException("GOT table base changed");
            long[][] switchCases={
                {0x55e82cL,0xfe7c80L,0x55e834L,0x55e8bcL,0x55e944L,0x55e9ccL,0x55ea54L},
                {0x55f590L,0xfe7c94L,0x55f598L,0x55f620L,0x55f6a8L,0x55f730L,0x55f7b8L}
            };
            for(long[] spec:switchCases){
                ArrayList<Address> destinations=new ArrayList<>();
                for(int i=0;i<5;i++){
                    long raw=Integer.toUnsignedLong(currentProgram.getMemory().getInt(toAddr(spec[1]+4*i)));
                    long derived=(raw+gp)&0xffffffffL;
                    if(derived!=spec[i+2])throw new IllegalStateException("raw table target mismatch");
                    if(currentProgram.getListing().getInstructionAt(toAddr(derived))==null)throw new IllegalStateException("case instruction absent");
                    destinations.add(toAddr(derived));
                }
                new JumpTable(toAddr(spec[0]),destinations,true,0).writeOverride(function);
                Map<String,Object> row=new LinkedHashMap<>();
                row.put("dispatch_site",toAddr(spec[0]).toString());row.put("table_address",toAddr(spec[1]).toString());
                row.put("case_destinations",destinations.stream().map(Object::toString).toList());
                row.put("basis","raw ELF/loaded-memory table words plus explicit PIC gp=0x10cc310 invariant, not runtime observation");
                row.put("ephemeral_jumptable_override",true);switches.add(row);
            }
            success=true;
        } finally { currentProgram.endTransaction(tx,success); }
        Map<String,Object> result=new LinkedHashMap<>();
        result.put("target_sha256",SHA);result.put("ranges",rows);result.put("switches",switches);
        result.put("target_executed",false);result.put("target_bytes_written",false);
        result.put("analysis_database_saved",false);result.put("auto_analysis",false);
        result.put("basis","Existing raw MIPS index records 40 MImg::Set calls in these two listing gaps; only metadata decoded inside explicit ranges");
        Files.writeString(output.resolve("settings-gap-decode.json"),new GsonBuilder().setPrettyPrinting().serializeNulls().create().toJson(result),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);
    }
}
