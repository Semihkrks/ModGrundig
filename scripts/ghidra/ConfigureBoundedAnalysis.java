// Avoid the observed pathological whole-program MIPS constant-propagation pass.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.framework.options.Options;
import ghidra.program.model.listing.Program;
import com.google.gson.GsonBuilder;
import java.nio.file.*;
import java.util.*;

public class ConfigureBoundedAnalysis extends GhidraScript {
    @Override public void run() throws Exception {
        Options options = currentProgram.getOptions(Program.ANALYSIS_PROPERTIES);
        Map<String,Object> changed = new LinkedHashMap<>();
        for (String name : options.getOptionNames()) {
            if (!name.contains(".") && name.toLowerCase().contains("mips") && name.toLowerCase().contains("constant")) {
                changed.put(name, Map.of("before", options.getBoolean(name, true), "after", false));
                options.setBoolean(name, false);
                println("Disabled observed slow analyzer: " + name);
            }
        }
        if (changed.isEmpty()) throw new IllegalStateException("Expected MIPS constant analyzer option was not found");
        String[] args = getScriptArgs();
        Files.createDirectories(Paths.get(args[0]));
        Map<String,Object> record = new LinkedHashMap<>();
        record.put("changed_options", changed);
        record.put("reason", "Whole-program pass produced VarnodeContext errors and long-running symbolic propagation; thread dump retained.");
        record.put("limitation", "Computed-address references may be missing; direct-call graph and decompiler are separate static analyses.");
        Files.writeString(Paths.get(args[0], "analysis-options.json"), new GsonBuilder().setPrettyPrinting().create().toJson(record));
    }
}
