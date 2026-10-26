// Bounded analysis fragments, not original standalone functions or whole-function C.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class SettingsFragmentExport extends GhidraScript {
    private static final String SHA="51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916";
    private final Gson gson=new GsonBuilder().setPrettyPrinting().serializeNulls().disableHtmlEscaping().create();
    private Path output;
    private Address at(String value){return toAddr(Long.parseUnsignedLong(value.replaceFirst("^0x",""),16));}
    private void write(String name,Object value)throws Exception{Files.writeString(output.resolve(name),gson.toJson(value),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);}
    private Map<String,Object> instruction(Instruction ins){
        Map<String,Object> row=new LinkedHashMap<>();
        row.put("address",ins.getAddress().toString());row.put("instruction",ins.toString());
        row.put("flow_type",ins.getFlowType().toString());row.put("flow_override",ins.getFlowOverride().toString());
        row.put("flows",Arrays.stream(ins.getFlows()).map(Object::toString).toList());
        row.put("fallthrough",ins.getFallThrough()==null?null:ins.getFallThrough().toString());
        row.put("delay_slots",ins.getDelaySlotDepth());return row;
    }
    @Override public void run()throws Exception{
        String[] args=getScriptArgs();
        if(args.length!=4)throw new IllegalArgumentException("manifest output comma-separated-phase-ids timeout-seconds");
        if(!SHA.equals(currentProgram.getExecutableSHA256()))throw new IllegalStateException("target mismatch");
        Path manifest=Path.of(args[0]);output=Path.of(args[1]);
        if(!Files.isDirectory(output,LinkOption.NOFOLLOW_LINKS)||Files.isSymbolicLink(output))throw new IllegalArgumentException("fresh existing output directory required");
        JsonObject plan=JsonParser.parseString(Files.readString(manifest,StandardCharsets.UTF_8)).getAsJsonObject();
        if(!SHA.equals(plan.get("target_sha256").getAsString()))throw new IllegalStateException("manifest target mismatch");
        int timeout=Integer.parseInt(args[3]);if(timeout<1||timeout>120)throw new IllegalArgumentException("fragment timeout must be1..120");
        Set<String> selected=new LinkedHashSet<>(Arrays.asList(args[2].split(",")));
        List<JsonObject> phases=new ArrayList<>();
        for(JsonElement value:plan.getAsJsonArray("phases")){JsonObject phase=value.getAsJsonObject();if(selected.contains(phase.get("id").getAsString()))phases.add(phase);}
        if(phases.size()!=selected.size()||phases.size()>3)throw new IllegalArgumentException("select 1..3 existing natural phases for smoke");
        FunctionManager manager=currentProgram.getFunctionManager();
        Function original=manager.getFunctionAt(toAddr(0x55b6c0L));
        if(original==null)throw new IllegalStateException("original function missing");
        Map<String,Object> originalFacts=Map.of("entry",original.getEntryPoint().toString(),"signature",original.getSignature().toString(),"body_bytes",original.getBody().getNumAddresses());
        List<Map<String,Object>> changes=new ArrayList<>();List<Function> fragments=new ArrayList<>();
        List<List<Map<String,Object>>> originals=new ArrayList<>(),analysisInventories=new ArrayList<>();
        List<String> analysisEnds=new ArrayList<>();
        int tx=currentProgram.startTransaction("Unsaved Settings natural-phase fragments with explicit boundary abstractions");boolean applied=false;
        try{
            // Removing only function metadata leaves original instruction/data bytes intact.
            if(!manager.removeFunction(original.getEntryPoint()))throw new IllegalStateException("cannot remove original function metadata");
            changes.add(Map.of("kind","original_function_metadata_removed","original",originalFacts,"target_bytes_modified",false));
            for(JsonObject phase:phases){
                String id=phase.get("id").getAsString();Address start=at(phase.get("start").getAsString()),naturalEnd=at(phase.get("end_exclusive").getAsString()),end=naturalEnd;
                AddressSet naturalBody=new AddressSet(start,naturalEnd.subtract(1));
                List<Map<String,Object>> before=new ArrayList<>();List<Instruction> naturalListing=new ArrayList<>();
                InstructionIterator naturalIterator=currentProgram.getListing().getInstructions(naturalBody,true);
                while(naturalIterator.hasNext()){Instruction ins=naturalIterator.next();before.add(instruction(ins));naturalListing.add(ins);}
                if(naturalListing.size()!=phase.get("instruction_count").getAsInt())throw new IllegalStateException("manifest/listing instruction mismatch "+id);
                Instruction naturalLast=naturalListing.get(naturalListing.size()-1),naturalPrevious=naturalListing.size()>1?naturalListing.get(naturalListing.size()-2):null;
                Set<Address> noreturnSites=new HashSet<>();for(JsonElement value:phase.getAsJsonArray("noreturn_call_candidates"))noreturnSites.add(at(value.getAsJsonObject().get("site").getAsString()));
                boolean terminalDelay=naturalPrevious!=null&&naturalLast.getMnemonicString().replaceFirst("^_","").equals("nop")&&(naturalPrevious.getFlowType().isTerminal()||noreturnSites.contains(naturalPrevious.getAddress())||naturalPrevious.getFlowType().isJump()&&!naturalPrevious.getFlowType().isConditional());
                boolean callRestoreTail=naturalListing.size()>2&&naturalListing.get(naturalListing.size()-3).getFlowType().isCall()&&naturalPrevious.getMnemonicString().replaceFirst("^_","").equals("nop")&&naturalLast.getMnemonicString().equals("lw")&&naturalLast.getDefaultOperandRepresentation(0).equals("gp");
                Address extendedBoundaryCall=null;
                if(!terminalDelay&&!callRestoreTail){
                    if(phases.size()!=1)throw new IllegalStateException("Phase requiring next-call exit adapter must run alone: "+id);
                    // Preserve final stores and loop conditions by including the next
                    // phase's short prefix through its first call. This overlap is an
                    // explicit analysis adapter, not extra original phase ownership.
                    Address cursor=naturalEnd;
                    for(int searched=0;searched<128&&cursor.compareTo(toAddr(0x579360L))<0;searched++,cursor=cursor.add(4)){
                        Instruction ins=currentProgram.getListing().getInstructionAt(cursor);
                        if(ins==null)throw new IllegalStateException("missing adapter-prefix instruction at "+cursor);
                        if(ins.getFlowType().isCall()){extendedBoundaryCall=cursor;end=cursor.add(4L*(1+ins.getDelaySlotDepth()));break;}
                    }
                    if(extendedBoundaryCall==null)throw new IllegalStateException("no reviewed existing-call boundary adapter within128instructions: "+id);
                    changes.add(Map.of("kind","next_phase_prefix_exit_adapter","fragment",id,"natural_end_exclusive",naturalEnd.toString(),"analysis_end_exclusive",end.toString(),"terminal_call",extendedBoundaryCall.toString(),"assumption","Additional original instructions from next phase preserve final stores/loop exits before a metadata-only terminating call. Prefix is not owned by this natural phase."));
                }
                AddressSet body=new AddressSet(start,end.subtract(1));
                Iterator<Function> overlaps=manager.getFunctionsOverlapping(body);
                if(overlaps.hasNext())throw new IllegalStateException("unexpected overlapping function "+overlaps.next().getEntryPoint());
                List<Map<String,Object>> analysisBefore=new ArrayList<>();List<Instruction> listing=new ArrayList<>();
                InstructionIterator iterator=currentProgram.getListing().getInstructions(body,true);
                while(iterator.hasNext()){Instruction ins=iterator.next();analysisBefore.add(instruction(ins));listing.add(ins);}
                Function function=manager.createFunction("Settings_fragment_"+id,start,body,SourceType.USER_DEFINED);
                if(function==null)throw new IllegalStateException("function creation failed "+id);
                function.setReturnType(Undefined4DataType.dataType,SourceType.USER_DEFINED);
                ReturnParameterImpl result=new ReturnParameterImpl(function.getReturn(),currentProgram);
                List<Parameter> params=new ArrayList<>();
                DataType pointer=PointerDataType.getPointer(ByteDataType.dataType,currentProgram.getDataTypeManager());
                for(String reg:List.of("a0","a1","a2","a3"))params.add(new ParameterImpl("boundary_"+reg,UnsignedIntegerDataType.dataType,currentProgram.getRegister(reg),currentProgram,SourceType.USER_DEFINED));
                if(!start.equals(toAddr(0x55b6c0L)))params.add(new ParameterImpl("original_frame_context",pointer,currentProgram.getRegister("s8"),currentProgram,SourceType.USER_DEFINED));
                function.updateFunction(currentProgram.getCompilerSpec().getDefaultCallingConvention().getName(),result,Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED,params.toArray(new Parameter[0]));
                currentProgram.getProgramContext().setValue(currentProgram.getRegister("gp"),start,start,BigInteger.valueOf(0x10cc310L));
                if(start.equals(toAddr(0x55b6c0L)))currentProgram.getProgramContext().setValue(currentProgram.getRegister("t9"),start,start,BigInteger.valueOf(0x55b6c0L));
                changes.add(Map.of("kind","fragment_context","fragment",id,"gp_hex","0x10cc310","t9_seed",start.equals(toAddr(0x55b6c0L))?"original_function_entry_0x55b6c0":"none_fragment_not_PIC_entry","s8_input",start.equals(toAddr(0x55b6c0L))?"original_prologue_sets_s8":"explicit_original_frame_context_parameter_unknown_runtime_pointer"));
                Set<Address> internalSwitches=new HashSet<>();
                long[][] specs={{0x55e82cL,0x55e834L,0x55e8bcL,0x55e944L,0x55e9ccL,0x55ea54L},{0x55f590L,0x55f598L,0x55f620L,0x55f6a8L,0x55f730L,0x55f7b8L}};
                for(long[] spec:specs)if(body.contains(toAddr(spec[0]))){ArrayList<Address> destinations=new ArrayList<>();for(int i=1;i<spec.length;i++){if(!body.contains(toAddr(spec[i])))throw new IllegalStateException("switch target outside fragment");destinations.add(toAddr(spec[i]));}new JumpTable(toAddr(spec[0]),destinations,true,0).writeOverride(function);internalSwitches.add(toAddr(spec[0]));changes.add(Map.of("kind","retained_internal_switch_override","fragment",id,"dispatch",toAddr(spec[0]).toString(),"destinations",destinations.stream().map(Object::toString).toList(),"basis","raw table target validation by SettingsFillListingGaps pre-script"));}
                for(Instruction ins:listing){
                    if(ins.getFlowType().isCall()||ins.getFlowType().isTerminal())continue;
                    boolean outside=false;for(Address target:ins.getFlows())if(!body.contains(target))outside=true;
                    boolean computedJump=ins.getFlowType().isJump()&&ins.getFlowType().isComputed()&&!internalSwitches.contains(ins.getAddress());
                    if(outside||computedJump){
                        Map<String,Object> change=new LinkedHashMap<>();change.put("kind","external_or_unknown_jump_return_abstraction");change.put("fragment",id);change.put("original",instruction(ins));change.put("assumption","Return at fragment boundary abstracts continuation; not original standalone function behavior");
                        ins.setFlowOverride(FlowOverride.RETURN);change.put("modified",instruction(ins));changes.add(change);
                    }
                }
                // Native decompiler ignores a null fallthrough on a plain load. End
                // this selected smoke phase at its final call instead. The original
                // delay nop and trailing GP restore remain in the retained inventory.
                Instruction last=listing.get(listing.size()-1);Address fall=last.getFallThrough();
                if(extendedBoundaryCall!=null){
                    Instruction tail=currentProgram.getListing().getInstructionAt(extendedBoundaryCall);Map<String,Object> change=new LinkedHashMap<>();change.put("kind","adapter_call_return_boundary_abstraction");change.put("fragment",id);change.put("original_call",instruction(tail));tail.setFlowOverride(FlowOverride.CALL_RETURN);change.put("modified_call",instruction(tail));change.put("assumption","Next-phase prefix call terminates the analysis adapter; continuation is retained only in raw CFG.");changes.add(change);
                }else if(!terminalDelay&&fall!=null&&!body.contains(fall)){
                    Instruction tail=listing.get(listing.size()-3),delay=listing.get(listing.size()-2);
                    if(!tail.getFlowType().isCall()||!delay.getMnemonicString().replaceFirst("^_","").equals("nop")||!last.getMnemonicString().equals("lw")||!last.getDefaultOperandRepresentation(0).equals("gp"))throw new IllegalStateException("Boundary needs an explicit reviewed cut strategy: "+id);
                    Map<String,Object> change=new LinkedHashMap<>();change.put("kind","final_call_return_boundary_abstraction");change.put("fragment",id);change.put("original_call",instruction(tail));change.put("unrepresented_trailing_gp_restore",instruction(last));
                    tail.setFlowOverride(FlowOverride.CALL_RETURN);change.put("modified_call",instruction(tail));change.put("assumption","Final original call is modeled as terminating this analysis fragment. Original GP restore and next-phase continuation are retained as raw evidence, not represented in fragment C.");changes.add(change);
                }
                for(JsonElement value:phase.getAsJsonArray("noreturn_call_candidates")){
                    JsonObject candidate=value.getAsJsonObject();Address site=at(candidate.get("site").getAsString());String name=candidate.get("target").getAsString();
                    if(!Set.of("abort","_Unwind_Resume","__cxa_throw","__cxa_rethrow","__assert_fail","__stack_chk_fail").contains(name))throw new IllegalArgumentException("unexpected noreturn name");
                    Instruction ins=currentProgram.getListing().getInstructionAt(site);if(ins==null||!body.contains(site)||!ins.getFlowType().isCall())throw new IllegalStateException("noreturn site mismatch");
                    FunctionDefinitionDataType signature=new FunctionDefinitionDataType(name);signature.setReturnType(VoidDataType.dataType);signature.setNoReturn(true);HighFunctionDBUtil.writeOverride(function,site,signature);
                    changes.add(Map.of("kind","standard_noreturn_callsite_assumption","fragment",id,"original",instruction(ins),"name",name));ins.setFlowOverride(FlowOverride.CALL_RETURN);
                }
                function.setComment("Analysis fragment only; external jumps/continuation are abstracted as exits. Not original standalone code. Original frame/GP context required.");
                fragments.add(function);originals.add(before);analysisInventories.add(analysisBefore);analysisEnds.add(end.toString());
            }
            applied=true;
        }finally{currentProgram.endTransaction(tx,applied);}
        write("fragment-metadata-assumptions.json",changes);
        List<Map<String,Object>> reports=new ArrayList<>();
        DecompInterface decompiler=new DecompInterface();DecompileOptions options=new DecompileOptions();options.setMaxPayloadMBytes(64);decompiler.setOptions(options);decompiler.toggleSyntaxTree(true);decompiler.setSimplificationStyle("decompile");
        try{
            if(!decompiler.openProgram(currentProgram))throw new IllegalStateException("decompiler program open failed");decompiler.flushCache();
            for(int index=0;index<fragments.size();index++){
                Function function=fragments.get(index);JsonObject phase=phases.get(index);String id=phase.get("id").getAsString();
                DecompileResults result=decompiler.decompileFunction(function,timeout,monitor);
                Map<String,Object> row=new LinkedHashMap<>();row.put("id",id);row.put("natural_phase",phase);row.put("entry",function.getEntryPoint().toString());row.put("analysis_end_exclusive",analysisEnds.get(index));row.put("body_bytes",function.getBody().getNumAddresses());row.put("signature",function.getSignature().toString());row.put("instruction_count",originals.get(index).size());row.put("original_instructions",originals.get(index));row.put("analysis_instruction_count",analysisInventories.get(index).size());row.put("analysis_instructions_before_metadata_overrides",analysisInventories.get(index));
                row.put("fragment_decompile_complete",result.decompileCompleted());row.put("decompile_error",result.getErrorMessage());
                if(result.decompileCompleted()&&result.getDecompiledFunction()!=null){String name=id+".c";Files.writeString(output.resolve(name),result.getDecompiledFunction().getC(),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);row.put("fragment_C_file",name);}
                List<Map<String,Object>> calls=new ArrayList<>();Set<String> outsideBody=new TreeSet<>();HighFunction high=result.getHighFunction();
                if(high!=null){Iterator<PcodeOpAST> operations=high.getPcodeOps();while(operations.hasNext()){
                    PcodeOpAST op=operations.next();Address source=op.getSeqnum().getTarget();if(currentProgram.getMemory().contains(source)&&!function.getBody().contains(source))outsideBody.add(source.toString());
                    if(op.getOpcode()==PcodeOp.CALL||op.getOpcode()==PcodeOp.CALLIND){Map<String,Object> call=new LinkedHashMap<>();call.put("site",source.toString());call.put("opcode",op.getMnemonic());call.put("target_expression",op.getInput(0).toString());List<String> values=new ArrayList<>();for(int i=1;i<op.getNumInputs();i++)values.add(op.getInput(i).toString());call.put("arguments",values);calls.add(call);}
                }}
                row.put("high_function_present",high!=null);row.put("pcode_calls",calls);row.put("pcode_addresses_outside_fragment",outsideBody);row.put("pcode_within_fragment",high==null?null:outsideBody.isEmpty());row.put("valid_bounded_fragment_C",result.decompileCompleted()&&high!=null&&outsideBody.isEmpty());row.put("evidence_kind","bounded_analysis_fragment_C_with_explicit_metadata_exit_abstractions_not_whole_function_C");reports.add(row);write(id+".json",row);
            }
        }finally{decompiler.dispose();}
        Map<String,Object> summary=new LinkedHashMap<>();summary.put("target_sha256",SHA);summary.put("original_function",originalFacts);summary.put("phase_ids",selected);summary.put("fragment_count",reports.size());summary.put("fragment_C_complete_count",reports.stream().filter(r->Boolean.TRUE.equals(r.get("fragment_decompile_complete"))).count());summary.put("valid_bounded_fragment_C_count",reports.stream().filter(r->Boolean.TRUE.equals(r.get("valid_bounded_fragment_C"))).count());summary.put("whole_function_C_complete_count",0);summary.put("timeout_seconds_per_fragment",timeout);summary.put("target_executed",false);summary.put("target_bytes_modified",false);summary.put("analysis_database_saved",false);summary.put("auto_analysis",false);summary.put("limitations",List.of("Natural phases are not standalone original functions. Boundary exits and unknown jumps are explicit metadata-only abstractions.","GP is an original PIC invariant assumption; only original prologue entry receives t9=original entry. Other fragments use explicit unknown original s8 frame pointer context.","Original stack values, aliased objects, incoming cross-phase register values and exception entries remain context requirements.","Final-call termination omits only the separately recorded trailing GP restore from fragment C; raw phase inventory and original continuation edge remain intact.","C completion applies to fragments only, not NewUI_Settings. No branch/call/target bytes are patched."));write("summary.json",summary);
    }
}
