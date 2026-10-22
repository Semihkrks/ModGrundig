// Export static code relationships. Never execute the imported target.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.util.DefinedDataIterator;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

public class ExportFirmwareMap extends GhidraScript {
    private Path output;
    private void write(String name, Object value) throws Exception {
        try (Writer writer = Files.newBufferedWriter(output.resolve(name))) {
            new GsonBuilder().disableHtmlEscaping().setPrettyPrinting().create().toJson(value, writer);
        }
    }
    private String hex(Address address) { return "0x" + address.toString(); }
    private Map<String,Object> functionRow(Function function) {
        Map<String,Object> row = new LinkedHashMap<>();
        row.put("address", hex(function.getEntryPoint()));
        row.put("name", function.getName(true));
        row.put("signature", function.getSignature().toString());
        row.put("external", function.isExternal());
        row.put("thunk", function.isThunk());
        row.put("body_bytes", function.getBody().getNumAddresses());
        return row;
    }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("Expected output directory");
        output = Paths.get(args[0]);
        Files.createDirectories(output);
        FunctionManager manager = currentProgram.getFunctionManager();
        ReferenceManager references = currentProgram.getReferenceManager();
        List<Map<String,Object>> functions = new ArrayList<>();
        List<Map<String,Object>> callgraph = new ArrayList<>();
        List<Map<String,Object>> selected = new ArrayList<>();
        Pattern select = Pattern.compile("(?i)(ArResourceManager|MResourceManager|MResourcePkg|ArCecController|VolumeControl|VolumeFrame|VolumeBar|VolumePopup|VolumePanel|VolumeWidget|VolumeOsd|CecSettings|QuickSettingsFrame|ToolsMenuFrame|RemoteControl|KeyEvent|KeyHandler|KeyMapping|KeyMap|SoundSettings|AudioSettings|SourceSettings|MainMenuFrame|HomeScreen|HomeMenu|ArTvConf|ArSound)");
        FunctionIterator iterator = manager.getFunctions(true);
        while (iterator.hasNext() && !monitor.isCancelled()) {
            Function function = iterator.next();
            Map<String,Object> row = functionRow(function);
            functions.add(row);
            if (!function.isExternal()) {
                List<String> targets = new ArrayList<>();
                for (Function called : function.getCalledFunctions(monitor)) targets.add(hex(called.getEntryPoint()));
                Map<String,Object> graphRow = new LinkedHashMap<>();
                graphRow.put("from", hex(function.getEntryPoint()));
                graphRow.put("calls", targets);
                int callsites = 0;
                int computed = 0;
                InstructionIterator instructions = currentProgram.getListing().getInstructions(function.getBody(), true);
                while (instructions.hasNext()) {
                    Instruction instruction = instructions.next();
                    if (instruction.getFlowType().isCall()) {
                        callsites++;
                        if (instruction.getFlowType().isComputed()) computed++;
                    }
                }
                graphRow.put("callsite_count", callsites);
                graphRow.put("computed_callsite_count", computed);
                callgraph.add(graphRow);
            }
            if (select.matcher(function.getName(true)).find() && !function.isExternal() && !function.isThunk()) {
                Map<String,Object> detailed = new LinkedHashMap<>(row);
                List<String> calls = new ArrayList<>();
                for (Function called : function.getCalledFunctions(monitor)) calls.add(hex(called.getEntryPoint()) + " " + called.getName(true));
                detailed.put("calls", calls);
                List<Map<String,String>> incoming = new ArrayList<>();
                ReferenceIterator incomingReferences = references.getReferencesTo(function.getEntryPoint());
                while (incomingReferences.hasNext()) {
                    Reference reference = incomingReferences.next();
                    Function caller = manager.getFunctionContaining(reference.getFromAddress());
                    Map<String,String> edge = new LinkedHashMap<>();
                    edge.put("from", hex(reference.getFromAddress()));
                    edge.put("type", reference.getReferenceType().toString());
                    edge.put("function", caller == null ? null : caller.getName(true));
                    incoming.add(edge);
                }
                detailed.put("incoming_references", incoming);
                selected.add(detailed);
            }
        }
        write("functions.json", functions);
        write("callgraph.json", callgraph);
        write("selected-function-links.json", selected);
        println("Exported " + functions.size() + " functions and " + selected.size() + " selected relationship records");
        List<Map<String,Object>> strings = new ArrayList<>();
        Pattern stringSelect = Pattern.compile("(?i)(ARimages|volume|ResProfile|Image_res|mufirkey|OSD Selection|Grundig|DIGILINK|CEC|remote|keymap|HomeScreen|soundSetting|sourceSetting)");
        Iterator<Data> dataIterator = DefinedDataIterator.byDataType(currentProgram,
            type -> type instanceof ghidra.program.model.data.AbstractStringDataType);
        while (dataIterator.hasNext() && !monitor.isCancelled()) {
            Data data = dataIterator.next();
            Object value = data.getValue();
            if (value == null) continue;
            String text = value.toString();
            if (!stringSelect.matcher(text).find()) continue;
            Map<String,Object> row = new LinkedHashMap<>();
            row.put("address", hex(data.getAddress()));
            row.put("value", text);
            List<Map<String,String>> incoming = new ArrayList<>();
            ReferenceIterator refs = references.getReferencesTo(data.getAddress());
            while (refs.hasNext()) {
                Reference ref = refs.next();
                Function function = manager.getFunctionContaining(ref.getFromAddress());
                Map<String,String> edge = new LinkedHashMap<>();
                edge.put("from", hex(ref.getFromAddress()));
                edge.put("type", ref.getReferenceType().toString());
                edge.put("function", function == null ? null : function.getName(true));
                incoming.add(edge);
            }
            row.put("incoming_references", incoming);
            strings.add(row);
        }
        write("ui-strings-xrefs.json", strings);
        DecompInterface decompiler = new DecompInterface();
        int decompiled = 0;
        List<Map<String,Object>> decompilation = new ArrayList<>();
        Pattern narrow = Pattern.compile("(?i)(ArResourceManager.*(SetBrand|GetOSDBrand|SetRemote|Init|Load)|MResourcePkg|MResourceManager.*(GetDFBImage|RenderImage)|VolumeControl|ArAudioManager.*(Volume|Mute)|ArCecController.*(ActiveSource|SetSource|Power|Key|UserControl|Init)|CecSettingsFrame.*(OnKey|OnCreate)|QuickSettingsFrame.*Digilink|ToolsMenuFrame.*Digilink|main$)");
        try {
            decompiler.openProgram(currentProgram);
            iterator = manager.getFunctions(true);
            while (iterator.hasNext() && !monitor.isCancelled()) {
                Function function = iterator.next();
                if (!narrow.matcher(function.getName(true)).find() || function.isExternal() || function.isThunk()) continue;
                Map<String,Object> record = functionRow(function);
                DecompileResults result = decompiler.decompileFunction(function, 30, monitor);
                record.put("complete", result.decompileCompleted());
                record.put("error", result.getErrorMessage());
                if (result.decompileCompleted()) {
                    String filename = function.getEntryPoint().toString() + ".c";
                    Files.writeString(output.resolve(filename), result.getDecompiledFunction().getC());
                    record.put("pseudocode_file", filename);
                    decompiled++;
                }
                decompilation.add(record);
            }
        } finally { decompiler.dispose(); }
        write("decompilation-index.json", decompilation);
        Map<String,Object> summary = new LinkedHashMap<>();
        summary.put("program", currentProgram.getName());
        summary.put("language", currentProgram.getLanguageID().toString());
        summary.put("compiler", currentProgram.getCompilerSpec().getCompilerSpecID().toString());
        summary.put("functions", functions.size());
        summary.put("selected_function_links", selected.size());
        summary.put("ui_strings", strings.size());
        summary.put("decompiled_selected_functions", decompiled);
        summary.put("target_executed", false);
        summary.put("limitations", List.of("Static analysis only; no TV runtime observation.",
            "Direct Ghidra workflow; REA refused missing inspected MIPS ABI record.",
            "Indirect calls and FP ABI semantics can remain unresolved.",
            "Selected xrefs and decompilation do not establish complete application behavior."));
        write("summary.json", summary);
        println("Exported " + strings.size() + " selected strings and " + decompiled + " pseudocode files");
    }
}
