// Correct only the selected function's input metadata from explicit MIPS evidence.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.data.*;
import ghidra.program.model.symbol.SourceType;
import com.google.gson.GsonBuilder;
import java.util.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class SettingsCorrectAbi extends GhidraScript {
    public void run() throws Exception {
        if(getScriptArgs().length!=1)throw new IllegalArgumentException("output directory required");
        if(!"51f6bd24ea6f1a152aa7142e2b993dcd615d01840a7127a3cc2484fe29748916".equals(currentProgram.getExecutableSHA256()))throw new IllegalStateException("target mismatch");
        Function function=currentProgram.getFunctionManager().getFunctionAt(toAddr(0x55b6c0L));
        if(function==null)throw new IllegalStateException("selected function absent");
        Map<String,Object> beforeFacts=new LinkedHashMap<>();
        beforeFacts.put("signature",function.getSignature().toString());
        beforeFacts.put("calling_convention",function.getCallingConventionName());
        beforeFacts.put("automatic_parameter_count",function.getAutoParameterCount());
        List<Map<String,Object>> originalParameters=new ArrayList<>();
        for(Parameter parameter:function.getParameters())originalParameters.add(Map.of("name",parameter.getName(),"type",parameter.getDataType().getPathName(),"storage",parameter.getVariableStorage().toString(),"automatic",parameter.isAutoParameter()));
        beforeFacts.put("parameters",originalParameters);
        Files.writeString(Path.of(getScriptArgs()[0]).resolve("settings-abi-before.json"),new GsonBuilder().setPrettyPrinting().serializeNulls().create().toJson(beforeFacts),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);
        if(function.getParameterCount()!=1||function.getAutoParameterCount()!=0)throw new IllegalStateException("unexpected original ABI; inspect settings-abi-before.json before applying any correction");
        DataType frameType=function.getParameter(0).getDataType();
        if(!(frameType instanceof Pointer)||!frameType.getDisplayName().contains("MMainFrame"))throw new IllegalStateException("original frame pointer type absent");
        String before=function.getSignature().toString();
        String previousConvention=function.getCallingConventionName();
        String returnTypeBefore=function.getReturnType().getPathName();
        String returnStorageBefore=function.getReturn().getVariableStorage().toString();
        ReturnParameterImpl preservedReturn=new ReturnParameterImpl(function.getReturn(),currentProgram);
        DataType managerTarget=VoidDataType.dataType;
        List<DataType> candidates=new ArrayList<>();
        currentProgram.getDataTypeManager().findDataTypes("ArUIManager",candidates);
        for(DataType candidate:candidates)if(candidate instanceof Structure){managerTarget=candidate;break;}
        DataType managerType=PointerDataType.getPointer(managerTarget,currentProgram.getDataTypeManager());
        ParameterImpl manager=new ParameterImpl("manager",managerType,currentProgram.getRegister("a0"),currentProgram,SourceType.USER_DEFINED);
        ParameterImpl frame=new ParameterImpl("frame",frameType,currentProgram.getRegister("a1"),currentProgram,SourceType.USER_DEFINED);
        String defaultConvention=currentProgram.getCompilerSpec().getDefaultCallingConvention().getName();
        int tx=currentProgram.startTransaction("Settings explicit a0/a1 input ABI metadata");
        boolean success=false;
        try {
            function.updateFunction(defaultConvention,preservedReturn,Function.FunctionUpdateType.CUSTOM_STORAGE,true,SourceType.USER_DEFINED,manager,frame);
            if(function.getParameterCount()!=2||function.getAutoParameterCount()!=0)throw new IllegalStateException("unexpected auto/explicit parameters");
            if(!returnTypeBefore.equals(function.getReturnType().getPathName())||!returnStorageBefore.equals(function.getReturn().getVariableStorage().toString()))throw new IllegalStateException("return metadata changed");
            success=true;
        } finally { currentProgram.endTransaction(tx,success); }
        Map<String,Object> result=new LinkedHashMap<>();
        result.put("function","0055b6c0");result.put("before",before);result.put("after",function.getSignature().toString());
        result.put("previous_calling_convention",previousConvention);result.put("calling_convention",defaultConvention);
        result.put("custom_variable_storage",function.hasCustomVariableStorage());result.put("automatic_parameters",function.getAutoParameterCount());
        List<Map<String,Object>> parameters=new ArrayList<>();
        for(Parameter parameter:function.getParameters())parameters.add(Map.of("name",parameter.getName(),"type",parameter.getDataType().getPathName(),"storage",parameter.getVariableStorage().toString()));
        result.put("parameters",parameters);result.put("preserved_return_type",returnTypeBefore);result.put("preserved_return_storage",returnStorageBefore);
        result.put("basis",List.of("ELF _ZN11ArUIManager14NewUI_SettingsEP10MMainFrame", "0055b6e8 saves a0 at frame+0x16e0;0055b6ec saves a1 at frame+0x16e4", "0055b718 loads saved a1 as MoveWindowTo receiver;0055b728 calls it"));
        result.put("manager_layout_status",managerTarget instanceof VoidDataType?"unknown_void_pointer_not_invented":"existing_analyzed_ArUIManager_structure_reused");
        result.put("return_semantics","preserved_unspecified_not_reinterpreted");
        result.put("analysis_database_saved",false);result.put("target_bytes_written",false);result.put("target_executed",false);
        Files.writeString(Path.of(getScriptArgs()[0]).resolve("settings-abi-correction.json"),new GsonBuilder().setPrettyPrinting().serializeNulls().create().toJson(result),StandardCharsets.UTF_8,StandardOpenOption.CREATE_NEW);
    }
}
