// Query only caller-selected functions in an existing project. No target execution.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.lang.Register;
import ghidra.program.model.data.FunctionDefinitionDataType;
import ghidra.program.model.data.VoidDataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.pcode.*;
import ghidra.program.model.symbol.*;
import com.google.gson.*;
import java.io.*;
import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.nio.file.*;
import java.util.*;

public class ExportUiSelection extends GhidraScript {
    // Optional, explicit native analysis-group controls. Never changes target bytes.
    private static class SelectedGroupOptions extends DecompileOptions {
        final Map<String,Boolean> groups = new LinkedHashMap<>();
        @Override public void encode(Encoder encoder, DecompInterface iface) throws IOException {
            if (groups.isEmpty()) { super.encode(encoder, iface); return; }
            Encoder intercepted = (Encoder)java.lang.reflect.Proxy.newProxyInstance(
                Encoder.class.getClassLoader(), new Class<?>[]{Encoder.class}, (proxy, method, args) -> {
                    if (method.getName().equals("closeElement") && args != null && args.length == 1 && args[0].equals(ElementId.ELEM_OPTIONSLIST)) {
                        for (Map.Entry<String,Boolean> group : groups.entrySet()) {
                            encoder.openElement(ElementId.ELEM_CURRENTACTION);
                            ElementId[] params = {ElementId.ELEM_PARAM1, ElementId.ELEM_PARAM2, ElementId.ELEM_PARAM3};
                            String[] values = {iface.getSimplificationStyle(), group.getKey(), group.getValue() ? "on" : "off"};
                            for (int i=0;i<params.length;i++) {
                                encoder.openElement(params[i]);
                                encoder.writeString(AttributeId.ATTRIB_CONTENT, values[i]);
                                encoder.closeElement(params[i]);
                            }
                            encoder.closeElement(ElementId.ELEM_CURRENTACTION);
                        }
                    }
                    try { return method.invoke(encoder, args); }
                    catch (java.lang.reflect.InvocationTargetException failure) { throw failure.getCause(); }
                });
            super.encode(intercepted, iface);
        }
    }
    private Path output;
    private final Gson gson = new GsonBuilder().disableHtmlEscaping().serializeNulls().setPrettyPrinting().create();
    private String address(Address value) { return value == null ? null : value.toString(); }
    private void write(String name, Object value) throws Exception {
        try (Writer writer = Files.newBufferedWriter(output.resolve(name), StandardCharsets.UTF_8, StandardOpenOption.CREATE_NEW)) {
            gson.toJson(value, writer);
        }
    }
    private Map<String,Object> functionRow(Function function) {
        Map<String,Object> row = new LinkedHashMap<>();
        if (function == null) return row;
        row.put("address", address(function.getEntryPoint()));
        row.put("name", function.getName(true));
        row.put("signature", function.getSignature().toString());
        row.put("external", function.isExternal());
        row.put("thunk", function.isThunk());
        row.put("body_bytes", function.getBody().getNumAddresses());
        return row;
    }
    private Map<String,Object> referenceRow(Reference reference) {
        Map<String,Object> row = new LinkedHashMap<>();
        row.put("from", address(reference.getFromAddress()));
        row.put("to", address(reference.getToAddress()));
        row.put("type", reference.getReferenceType().toString());
        row.put("source_type", reference.getSource().toString());
        row.put("operand_index", reference.getOperandIndex());
        row.put("is_call", reference.getReferenceType().isCall());
        row.put("from_function", functionRow(currentProgram.getFunctionManager().getFunctionContaining(reference.getFromAddress())));
        Symbol symbol = currentProgram.getSymbolTable().getPrimarySymbol(reference.getToAddress());
        row.put("target_symbol", symbol == null ? null : symbol.getName(true));
        return row;
    }
    private Map<String,Object> definedString(Address target) {
        Data data = currentProgram.getListing().getDefinedDataContaining(target);
        if (data == null || !data.hasStringValue()) return null;
        Object value = data.getValue();
        if (value == null) return null;
        String text = value.toString();
        Map<String,Object> row = new LinkedHashMap<>();
        row.put("address", address(data.getAddress()));
        row.put("reference_target", address(target));
        row.put("datatype", data.getDataType().getName());
        row.put("byte_length", data.getLength());
        boolean sensitive = text.contains("-----BEGIN PRIVATE KEY-----") || text.contains("-----BEGIN RSA PRIVATE KEY-----") || text.contains("-----BEGIN CERTIFICATE-----");
        row.put("value", sensitive ? null : text);
        row.put("content_omitted_sensitive_material", sensitive);
        return row;
    }
    private Long loadedValue(long offset, int size) {
        if (size < 1 || size > 8) return null;
        try {
            Address location = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(offset);
            byte[] bytes = new byte[size];
            if (currentProgram.getMemory().getBytes(location, bytes) != size) return null;
            long value = 0;
            for (int index = 0; index < size; index++) {
                int selected = currentProgram.getLanguage().isBigEndian() ? index : size - index - 1;
                value = (value << 8) | (bytes[selected] & 0xffL);
            }
            return value;
        } catch (Exception ignored) { return null; }
    }
    private Long constantValue(Varnode node, int depth) {
        if (node == null || depth > 16) return null;
        if (node.isConstant()) return node.getOffset();
        PcodeOp definition = node.getDef();
        if (definition == null) return node.isAddress() ? loadedValue(node.getOffset(), node.getSize()) : null;
        int opcode = definition.getOpcode();
        if (opcode == PcodeOp.COPY || opcode == PcodeOp.CAST || opcode == PcodeOp.INT_ZEXT || opcode == PcodeOp.INT_SEXT) {
            Long value = constantValue(definition.getInput(0), depth + 1);
            if (value != null && opcode == PcodeOp.INT_SEXT) {
                int shift = 64 - definition.getInput(0).getSize() * 8;
                if (shift > 0) value = (value << shift) >> shift;
            }
            return normalized(value, node.getSize());
        }
        if (opcode == PcodeOp.LOAD) {
            Long pointer = constantValue(definition.getInput(1), depth + 1);
            return pointer == null ? null : loadedValue(pointer, node.getSize());
        }
        if (definition.getNumInputs() < 2) return null;
        Long left = constantValue(definition.getInput(0), depth + 1);
        Long right = constantValue(definition.getInput(1), depth + 1);
        if (left == null || right == null) return null;
        switch (opcode) {
            case PcodeOp.INT_ADD: case PcodeOp.PTRSUB: return normalized(left + right, node.getSize());
            case PcodeOp.INT_SUB: return normalized(left - right, node.getSize());
            case PcodeOp.INT_AND: return normalized(left & right, node.getSize());
            case PcodeOp.INT_OR: return normalized(left | right, node.getSize());
            case PcodeOp.INT_LEFT: return normalized(left << right, node.getSize());
            case PcodeOp.PTRADD:
                Long scale = constantValue(definition.getInput(2), depth + 1);
                return scale == null ? null : normalized(left + right * scale, node.getSize());
            default: return null;
        }
    }
    private Long normalized(Long value, int size) {
        if (value == null || size >= 8) return value;
        return value & ((1L << (size * 8)) - 1);
    }
    private Map<String,Object> stringAtConstant(Long value, Address source) {
        if (value == null) return null;
        try {
            Address target = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(value);
            Map<String,Object> string = definedString(target);
            if (string != null) {
                string.put("pcode_source_address", address(source));
                string.put("basis", "decompiler_constant_or_read_of_analyzed_loaded_memory_not_runtime_value");
            }
            return string;
        } catch (Exception ignored) { return null; }
    }
    private Long picGp(Function function) {
        Instruction first = currentProgram.getListing().getInstructionAt(function.getEntryPoint());
        if (first == null || !first.getMnemonicString().equals("lui") || !first.getDefaultOperandRepresentation(0).equals("gp")) return null;
        Instruction second = first.getNext();
        Instruction third = second == null ? null : second.getNext();
        if (second == null || third == null || !second.getMnemonicString().equals("addiu") || !second.getDefaultOperandRepresentation(0).equals("gp") || !second.getDefaultOperandRepresentation(1).equals("gp") || !third.toString().equals("addu gp,gp,t9")) return null;
        Scalar high = first.getScalar(1);
        Scalar low = second.getScalar(2);
        if (high == null || low == null) return null;
        return (function.getEntryPoint().getOffset() + (high.getUnsignedValue() << 16) + low.getSignedValue()) & 0xffffffffL;
    }
    private List<Map<String,Object>> applyNoReturnAssumptions(List<Function> functions, Set<String> names) throws Exception {
        List<Map<String,Object>> changes = new ArrayList<>();
        FunctionIterator externals = currentProgram.getFunctionManager().getExternalFunctions();
        while (externals.hasNext()) {
            Function external = externals.next();
            if (!names.contains(external.getName())) continue;
            boolean previous = external.hasNoReturn();
            external.setNoReturn(true);
            changes.add(Map.of("kind", "external_function_noreturn", "name", external.getName(), "address", address(external.getEntryPoint()), "previous_noreturn", previous, "basis", "explicit_standard_abort_or_throw_semantics_assumption_not_target_execution"));
        }
        for (Function function : functions) {
            Long gp = picGp(function);
            if (gp == null) continue;
            Address pendingSlot = null;
            InstructionIterator iterator = currentProgram.getListing().getInstructions(function.getBody(), true);
            while (iterator.hasNext()) {
                Instruction instruction = iterator.next();
                String mnemonic = instruction.getMnemonicString().replaceFirst("^_", "");
                if (mnemonic.equals("lw") && instruction.getDefaultOperandRepresentation(0).equals("t9")) {
                    boolean gpRelative = false;
                    for (Object object : instruction.getOpObjects(1)) if (object instanceof Register && ((Register)object).getName().equals("gp")) gpRelative = true;
                    Scalar displacement = null;
                    for (Object object : instruction.getOpObjects(1)) if (object instanceof Scalar) displacement = (Scalar)object;
                    pendingSlot = gpRelative && displacement != null ? currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress((gp + displacement.getSignedValue()) & 0xffffffffL) : null;
                    continue;
                }
                if (instruction.getFlowType().isCall()) {
                    if (pendingSlot != null && mnemonic.equals("jalr") && instruction.getDefaultOperandRepresentation(0).equals("t9")) {
                        Symbol label = currentProgram.getSymbolTable().getPrimarySymbol(pendingSlot);
                        String matched = null;
                        Set<String> aliases = new LinkedHashSet<>();
                        if (label != null) aliases.add(label.getName());
                        for (Reference reference : currentProgram.getReferenceManager().getReferencesFrom(pendingSlot)) {
                            Symbol targetLabel = currentProgram.getSymbolTable().getPrimarySymbol(reference.getToAddress());
                            if (targetLabel != null) aliases.add(targetLabel.getName());
                        }
                        Data pointerData = currentProgram.getListing().getDefinedDataAt(pendingSlot);
                        if (pointerData != null && pointerData.getValue() instanceof Address) {
                            Symbol targetLabel = currentProgram.getSymbolTable().getPrimarySymbol((Address)pointerData.getValue());
                            if (targetLabel != null) aliases.add(targetLabel.getName());
                        }
                        for (String alias : aliases) for (String name : names) if (alias.equals(name) || alias.startsWith("PTR_" + name + "_")) matched = name;
                        if (matched != null) {
                            Map<String,Object> change = new LinkedHashMap<>();
                            change.put("kind", "selected_callsite_noreturn_override");
                            change.put("function", address(function.getEntryPoint()));
                            change.put("instruction", address(instruction.getAddress()));
                            change.put("got_slot", address(pendingSlot));
                            change.put("got_symbol", label == null ? null : label.getName(true));
                            change.put("got_target_aliases", aliases);
                            change.put("noreturn_name", matched);
                            change.put("derived_gp_hex", "0x" + Long.toHexString(gp));
                            change.put("original_flow_override", instruction.getFlowOverride().toString());
                            FunctionDefinitionDataType signature = new FunctionDefinitionDataType(matched);
                            signature.setReturnType(VoidDataType.dataType);
                            signature.setNoReturn(true);
                            HighFunctionDBUtil.writeOverride(function, instruction.getAddress(), signature);
                            instruction.setFlowOverride(FlowOverride.CALL_RETURN);
                            change.put("flow_override", instruction.getFlowOverride().toString());
                            change.put("basis", "linear_same_block_gp_relative_t9_load_to_named_GOT_slot_then_jalr; explicit_standard_noreturn_assumption");
                            changes.add(change);
                        }
                    }
                    pendingSlot = null;
                } else {
                    if (instruction.getFlowType().isJump()) pendingSlot = null;
                    for (Object object : instruction.getResultObjects()) if (object instanceof Register && ((Register)object).getName().equals("t9")) pendingSlot = null;
                }
            }
        }
        return changes;
    }
    private List<String> selectedAddresses(JsonElement configuration) {
        JsonArray values;
        if (configuration.isJsonArray()) values = configuration.getAsJsonArray();
        else values = configuration.getAsJsonObject().getAsJsonArray("addresses");
        if (values == null || values.isEmpty()) throw new IllegalArgumentException("Selection requires nonempty addresses array");
        LinkedHashSet<String> unique = new LinkedHashSet<>();
        for (JsonElement value : values) {
            if (!value.isJsonPrimitive() || !value.getAsJsonPrimitive().isString()) throw new IllegalArgumentException("Addresses must be strings");
            String selector = value.getAsString();
            if (!selector.matches("(?:0x)?[0-9a-fA-F]{1,16}")) throw new IllegalArgumentException("Invalid explicit hexadecimal address: " + selector);
            unique.add(selector.replaceFirst("^0x", ""));
        }
        return new ArrayList<>(unique);
    }
    private JsonElement readSelection(Path path) throws Exception {
        if (Files.isSymbolicLink(path) || !Files.isRegularFile(path, LinkOption.NOFOLLOW_LINKS)) throw new IllegalArgumentException("Selection must be a regular, non-symlink file");
        String content = Files.readString(path, StandardCharsets.UTF_8).trim();
        if (content.startsWith("[") || content.startsWith("{")) return JsonParser.parseString(content);
        JsonArray addresses = new JsonArray();
        for (String line : content.split("\\R")) {
            String selector = line.split("#", 2)[0].trim();
            if (!selector.isEmpty()) addresses.add(selector);
        }
        return addresses;
    }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("Expected selection JSON/text file and fresh output directory");
        Path selection = Paths.get(args[0]);
        output = Paths.get(args[1]);
        if (!Files.isDirectory(output, LinkOption.NOFOLLOW_LINKS) || Files.isSymbolicLink(output)) throw new IllegalArgumentException("Output directory must already exist and not be a symlink");
        JsonElement configuration = readSelection(selection);
        List<String> selectors = selectedAddresses(configuration);
        JsonObject options = configuration.isJsonObject() ? configuration.getAsJsonObject() : new JsonObject();
        if (options.has("target_sha256") && !options.get("target_sha256").getAsString().equalsIgnoreCase(currentProgram.getExecutableSHA256())) throw new IllegalArgumentException("Selected program's stored executable SHA256 differs from caller target identity");
        int timeout = options.has("decompile_timeout_seconds") ? options.get("decompile_timeout_seconds").getAsInt() : 60;
        if (timeout < 1 || timeout > 600) throw new IllegalArgumentException("decompile_timeout_seconds must be 1..600");
        boolean exportSyntaxTree = !options.has("export_syntax_tree") || options.get("export_syntax_tree").getAsBoolean();
        boolean emitCCode = !options.has("emit_c_code") || options.get("emit_c_code").getAsBoolean();
        String simplificationStyle = options.has("decompiler_simplification_style") ? options.get("decompiler_simplification_style").getAsString() : "decompile";
        if (!Set.of("decompile", "normalize", "firstpass").contains(simplificationStyle)) throw new IllegalArgumentException("Unsupported decompiler style");
        SelectedGroupOptions decompileOptions = new SelectedGroupOptions();
        if (options.has("decompiler_action_groups")) {
            Set<String> allowedGroups = Set.of("protorecovery", "protorecovery_b", "localrecovery", "stackptrflow", "stackvars", "typerecovery", "conditionalexe", "unreachable", "normalizebranches");
            for (Map.Entry<String,JsonElement> group : options.getAsJsonObject("decompiler_action_groups").entrySet()) {
                if (!allowedGroups.contains(group.getKey())) throw new IllegalArgumentException("Unsupported explicit action group: " + group.getKey());
                decompileOptions.groups.put(group.getKey(), group.getValue().getAsBoolean());
            }
        }
        Map<String,Object> analysisOptionOverrides = new LinkedHashMap<>();
        if (options.has("decompiler_simplify_predication")) {
            boolean value = options.get("decompiler_simplify_predication").getAsBoolean();
            decompileOptions.setPredicate(value);
            analysisOptionOverrides.put("simplify_predication", value);
        }
        if (options.has("decompiler_split_structures")) {
            boolean value = options.get("decompiler_split_structures").getAsBoolean();
            decompileOptions.setSplitStructures(value);
            analysisOptionOverrides.put("split_structures", value);
        }
        if (options.has("decompiler_split_arrays")) {
            boolean value = options.get("decompiler_split_arrays").getAsBoolean();
            decompileOptions.setSplitArrays(value);
            analysisOptionOverrides.put("split_arrays", value);
        }
        if (options.has("decompiler_split_pointers")) {
            boolean value = options.get("decompiler_split_pointers").getAsBoolean();
            decompileOptions.setSplitPointers(value);
            analysisOptionOverrides.put("split_pointers", value);
        }
        if (options.has("decompiler_max_payload_mbytes")) {
            int maximum = options.get("decompiler_max_payload_mbytes").getAsInt();
            if (maximum < 1 || maximum > 512) throw new IllegalArgumentException("decompiler_max_payload_mbytes must be 1..512");
            decompileOptions.setMaxPayloadMBytes(maximum);
        }
        boolean seedT9 = !options.has("seed_t9_entry") || options.get("seed_t9_entry").getAsBoolean();
        boolean clampBody = options.has("clamp_to_dynsym_size") && options.get("clamp_to_dynsym_size").getAsBoolean();
        JsonObject symbolSizes = options.has("symbol_sizes") ? options.getAsJsonObject("symbol_sizes") : new JsonObject();
        JsonObject functionBounds = options.has("function_bounds") ? options.getAsJsonObject("function_bounds") : new JsonObject();
        Set<String> noReturnNames = new LinkedHashSet<>();
        if (options.has("noreturn_names")) for (JsonElement name : options.getAsJsonArray("noreturn_names")) noReturnNames.add(name.getAsString());
        BigInteger gpSeed = options.has("gp_constant") ? new BigInteger(options.get("gp_constant").getAsString().replaceFirst("^0x", ""), 16) : null;
        FunctionManager manager = currentProgram.getFunctionManager();
        List<Function> functions = new ArrayList<>();
        List<Map<String,Object>> requested = new ArrayList<>();
        List<Map<String,Object>> seeds = new ArrayList<>();
        Register t9 = currentProgram.getRegister("t9");
        Register gp = currentProgram.getRegister("gp");
        int transaction = currentProgram.startTransaction("Ephemeral caller-selected MIPS PIC entry assumptions");
        boolean seeded = false;
        List<Map<String,Object>> noReturnChanges = new ArrayList<>();
        try {
            for (String selector : selectors) {
                Address entry = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(selector);
                Function function = manager.getFunctionAt(entry);
                Map<String,Object> request = new LinkedHashMap<>();
                request.put("requested_address", selector);
                request.put("function", functionRow(function));
                request.put("status", function == null ? "no_exact_function_entry" : "selected_existing_function");
                requested.add(request);
                if (function == null || function.isExternal()) continue;
                request.put("original_body_min", address(function.getBody().getMinAddress()));
                request.put("original_body_max", address(function.getBody().getMaxAddress()));
                if (functionBounds.has(selector)) {
                    JsonObject bound = functionBounds.getAsJsonObject(selector);
                    Address endExclusive = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(bound.get("end_exclusive").getAsString().replaceFirst("^0x", ""));
                    if (endExclusive.compareTo(entry) <= 0) throw new IllegalArgumentException("Invalid exclusive function bound for " + selector);
                    request.put("supplied_function_bound", bound);
                    function.setBody(new AddressSet(entry, endExclusive.subtract(1)));
                    request.put("ephemeral_exact_body_applied", true);
                    request.put("bounded_body", functionRow(function));
                }
                JsonObject suppliedSymbol = symbolSizes.has(selector) ? symbolSizes.getAsJsonObject(selector) : null;
                if (suppliedSymbol != null) {
                    long size = suppliedSymbol.get("size").getAsLong();
                    request.put("supplied_dynsym", suppliedSymbol);
                    if (size > 0) {
                        Address end = entry.add(size - 1);
                        boolean overrun = function.getBody().getNumAddresses() > size || function.getBody().getMaxAddress().compareTo(end) > 0 || function.getBody().getMinAddress().compareTo(entry) < 0;
                        request.put("body_exceeds_dynsym_size", overrun);
                        request.put("dynsym_end_inclusive", address(end));
                        if (overrun && clampBody) {
                            function.setBody(new AddressSet(entry, end));
                            request.put("ephemeral_body_clamped", true);
                            request.put("body_change_reason", "Original analyzed body exceeded caller-supplied ELF dynsym entry+size; bounded to declared contiguous range for this unsaved query only");
                            request.put("query_body", functionRow(function));
                        } else request.put("ephemeral_body_clamped", false);
                    }
                } else request.put("dynsym_boundary_status", "no_exact_positive_symbol_size_supplied");
                functions.add(function);
                if (seedT9) {
                    if (t9 == null) throw new IllegalStateException("Program lacks MIPS t9 register");
                    BigInteger value = new BigInteger(entry.getOffsetAsBigInteger().toString());
                    currentProgram.getProgramContext().setValue(t9, entry, entry, value);
                    seeds.add(Map.of("register", t9.getName(), "address", address(entry), "value_hex", value.toString(16), "basis", "assumed_MIPS_PIC_t9_equals_function_entry_not_runtime_measurement"));
                }
                if (gpSeed != null) {
                    if (gp == null) throw new IllegalStateException("Program lacks MIPS gp register");
                    currentProgram.getProgramContext().setValue(gp, entry, entry, gpSeed);
                    seeds.add(Map.of("register", gp.getName(), "address", address(entry), "value_hex", gpSeed.toString(16), "basis", "explicit_caller_supplied_constant_not_runtime_measurement"));
                }
            }
            noReturnChanges = applyNoReturnAssumptions(functions, noReturnNames);
            seeded = true;
        } finally { currentProgram.endTransaction(transaction, seeded); }
        write("selection-and-context.json", Map.of("requested", requested, "ephemeral_context_seeds", seeds, "ephemeral_noreturn_assumptions", noReturnChanges));

        List<Map<String,Object>> reports = new ArrayList<>();
        DecompInterface decompiler = new DecompInterface();
        try {
            decompiler.setOptions(decompileOptions);
            decompiler.setSimplificationStyle(simplificationStyle);
            decompiler.toggleSyntaxTree(exportSyntaxTree);
            decompiler.toggleCCode(emitCCode);
            if (!decompiler.openProgram(currentProgram)) throw new IllegalStateException("Decompiler could not open existing program");
            decompiler.flushCache();
            for (Function function : functions) {
                monitor.checkCancelled();
                Map<String,Object> report = functionRow(function);
                List<Map<String,Object>> incoming = new ArrayList<>();
                ReferenceIterator refs = currentProgram.getReferenceManager().getReferencesTo(function.getEntryPoint());
                while (refs.hasNext()) incoming.add(referenceRow(refs.next()));
                report.put("incoming_entry_xrefs", incoming);
                List<Map<String,Object>> callers = new ArrayList<>();
                for (Function caller : function.getCallingFunctions(monitor)) callers.add(functionRow(caller));
                report.put("analyzed_callers", callers);
                List<Map<String,Object>> callees = new ArrayList<>();
                for (Function called : function.getCalledFunctions(monitor)) callees.add(functionRow(called));
                report.put("analyzed_callees", callees);
                List<Map<String,Object>> instructions = new ArrayList<>();
                List<Map<String,Object>> scalars = new ArrayList<>();
                Map<String,Map<String,Object>> strings = new LinkedHashMap<>();
                int computedCalls = 0;
                InstructionIterator iterator = currentProgram.getListing().getInstructions(function.getBody(), true);
                while (iterator.hasNext()) {
                    monitor.checkCancelled();
                    Instruction instruction = iterator.next();
                    Map<String,Object> row = new LinkedHashMap<>();
                    row.put("address", address(instruction.getAddress()));
                    row.put("instruction", instruction.toString());
                    row.put("mnemonic", instruction.getMnemonicString());
                    row.put("flow_type", instruction.getFlowType().toString());
                    row.put("ephemeral_flow_override", instruction.getFlowOverride().toString());
                    row.put("delay_slots", instruction.getDelaySlotDepth());
                    List<Map<String,Object>> operands = new ArrayList<>();
                    for (int operand = 0; operand < instruction.getNumOperands(); operand++) {
                        Map<String,Object> op = new LinkedHashMap<>();
                        op.put("index", operand);
                        op.put("display", instruction.getDefaultOperandRepresentation(operand));
                        List<Map<String,Object>> objects = new ArrayList<>();
                        for (Object object : instruction.getOpObjects(operand)) {
                            Map<String,Object> value = new LinkedHashMap<>();
                            value.put("java_type", object.getClass().getSimpleName());
                            value.put("display", object.toString());
                            if (object instanceof Scalar) {
                                Scalar scalar = (Scalar)object;
                                value.put("unsigned_hex", "0x" + Long.toUnsignedString(scalar.getUnsignedValue(), 16));
                                value.put("signed_decimal", scalar.getSignedValue());
                                value.put("bits", scalar.bitLength());
                                Map<String,Object> constant = new LinkedHashMap<>(value);
                                constant.put("instruction_address", address(instruction.getAddress()));
                                constant.put("operand_index", operand);
                                constant.put("resource_id_status", "unclassified_immediate_not_proven_resource_id");
                                scalars.add(constant);
                            }
                            objects.add(value);
                        }
                        op.put("objects", objects);
                        operands.add(op);
                    }
                    row.put("operands", operands);
                    List<Map<String,Object>> instructionReferences = new ArrayList<>();
                    for (Reference reference : instruction.getReferencesFrom()) {
                        instructionReferences.add(referenceRow(reference));
                        Map<String,Object> string = definedString(reference.getToAddress());
                        if (string != null) {
                            string.put("referenced_from_instruction", address(instruction.getAddress()));
                            string.put("reference_type", reference.getReferenceType().toString());
                            strings.put(address(reference.getToAddress()) + ":" + address(instruction.getAddress()), string);
                        }
                    }
                    row.put("references_from", instructionReferences);
                    if (instruction.getFlowType().isCall() && instruction.getFlowType().isComputed()) computedCalls++;
                    instructions.add(row);
                }
                report.put("instruction_count", instructions.size());
                report.put("computed_callsite_count", computedCalls);
                report.put("instructions", instructions);
                report.put("immediate_scalar_candidates", scalars);
                report.put("directly_referenced_defined_strings", new ArrayList<>(strings.values()));
                DecompileResults result = decompiler.decompileFunction(function, timeout, monitor);
                report.put("syntax_tree_requested", exportSyntaxTree);
                report.put("C_code_requested", emitCCode);
                report.put("decompiler_simplification_style", simplificationStyle);
                report.put("high_function_present", result.getHighFunction() != null);
                report.put("decompile_complete", result.decompileCompleted());
                report.put("decompile_error", result.getErrorMessage());
                if (emitCCode && result.decompileCompleted() && result.getDecompiledFunction() != null && !result.getDecompiledFunction().getC().isBlank()) {
                    String filename = address(function.getEntryPoint()).replace(':', '_') + ".c";
                    Files.writeString(output.resolve(filename), result.getDecompiledFunction().getC(), StandardCharsets.UTF_8, StandardOpenOption.CREATE_NEW);
                    report.put("pseudocode_file", filename);
                }
                report.put("C_export_complete", report.containsKey("pseudocode_file"));
                List<Map<String,Object>> pcodeCalls = new ArrayList<>();
                Map<String,Map<String,Object>> constantStrings = new LinkedHashMap<>();
                Set<String> outsideBody = new TreeSet<>();
                try {
                if (result.getHighFunction() != null) {
                    Iterator<PcodeOpAST> operations = result.getHighFunction().getPcodeOps();
                    while (operations.hasNext()) {
                        PcodeOpAST operation = operations.next();
                        Address source = operation.getSeqnum().getTarget();
                        if (currentProgram.getMemory().contains(source) && !function.getBody().contains(source)) outsideBody.add(address(source));
                        int stringInputStart = operation.getOpcode() == PcodeOp.CALL ? 1 : 0;
                        for (int index = stringInputStart; index < operation.getNumInputs(); index++) {
                            Map<String,Object> string = stringAtConstant(constantValue(operation.getInput(index), 0), source);
                            if (string != null) constantStrings.put(string.get("address") + ":" + address(source), string);
                        }
                        if (operation.getOpcode() != PcodeOp.CALL && operation.getOpcode() != PcodeOp.CALLIND) continue;
                        Map<String,Object> call = new LinkedHashMap<>();
                        call.put("instruction_address", address(source));
                        call.put("pcode_opcode", operation.getMnemonic());
                        call.put("target_expression", operation.getInput(0).toString());
                        boolean directCall = operation.getOpcode() == PcodeOp.CALL;
                        Address directTarget = directCall ? operation.getInput(0).getAddress() : null;
                        Long target = directCall ? Long.valueOf(directTarget.getOffset()) : constantValue(operation.getInput(0), 0);
                        call.put("target_interpretation", directCall ? "literal_pcode_CALL_address_no_dereference" : "pcode_CALLIND_pointer_value_static_derivation");
                        call.put("direct_target_address_space", directCall ? directTarget.getAddressSpace().getName() : null);
                        call.put("constant_target_hex", target == null ? null : "0x" + Long.toUnsignedString(target, 16));
                        if (target != null) {
                            Address location = directCall ? directTarget : currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(target);
                            call.put("target_function", functionRow(manager.getFunctionAt(location)));
                            Symbol symbol = currentProgram.getSymbolTable().getPrimarySymbol(location);
                            call.put("target_symbol", symbol == null ? null : symbol.getName(true));
                        }
                        List<Map<String,Object>> arguments = new ArrayList<>();
                        for (int index = 1; index < operation.getNumInputs(); index++) {
                            Long value = constantValue(operation.getInput(index), 0);
                            Map<String,Object> argument = new LinkedHashMap<>();
                            argument.put("argument_index_zero_based", index - 1);
                            argument.put("expression", operation.getInput(index).toString());
                            argument.put("constant_hex", value == null ? null : "0x" + Long.toUnsignedString(value, 16));
                            argument.put("defined_string", stringAtConstant(value, source));
                            argument.put("resource_id_status", "not_proven_by_constant_alone");
                            arguments.add(argument);
                        }
                        call.put("arguments", arguments);
                        call.put("basis", "static_decompiler_pcode_with_ephemeral_entry_assumptions");
                        pcodeCalls.add(call);
                    }
                }
                report.put("pcode_export_complete", exportSyntaxTree && result.getHighFunction() != null);
                } catch (RuntimeException failure) {
                    report.put("pcode_export_complete", false);
                    report.put("pcode_export_error", failure.getClass().getName() + ": " + failure.getMessage());
                }
                report.put("decompiler_pcode_calls", pcodeCalls);
                report.put("decompiler_pcode_addresses_outside_selected_body", outsideBody);
                report.put("decompiler_pcode_within_selected_body", !exportSyntaxTree || result.getHighFunction() == null ? null : outsideBody.isEmpty());
                report.put("decompiler_constant_defined_strings", new ArrayList<>(constantStrings.values()));
                reports.add(report);
                write(address(function.getEntryPoint()).replace(':', '_') + ".json", report);
            }
        } finally { decompiler.dispose(); }
        Map<String,Object> summary = new LinkedHashMap<>();
        summary.put("program", currentProgram.getName());
        summary.put("project_program_path", currentProgram.getDomainFile().getPathname());
        summary.put("stored_executable_sha256", currentProgram.getExecutableSHA256());
        summary.put("language", currentProgram.getLanguageID().toString());
        summary.put("selection_file", selection.toString());
        summary.put("requested_count", selectors.size());
        summary.put("processed_count", reports.size());
        summary.put("decompile_complete_count", reports.stream().filter(row -> Boolean.TRUE.equals(row.get("decompile_complete"))).count());
        summary.put("C_export_complete_count", reports.stream().filter(row -> Boolean.TRUE.equals(row.get("C_export_complete"))).count());
        summary.put("ephemeral_context_seed_count", seeds.size());
        summary.put("ephemeral_noreturn_change_count", noReturnChanges.size());
        summary.put("decompile_timeout_seconds_per_function", timeout);
        summary.put("decompiler_max_payload_mbytes", decompileOptions.getMaxPayloadMBytes());
        summary.put("syntax_tree_requested", exportSyntaxTree);
        summary.put("C_code_requested", emitCCode);
        summary.put("decompiler_simplification_style", simplificationStyle);
        summary.put("analysis_option_overrides", analysisOptionOverrides);
        summary.put("decompiler_action_group_overrides", decompileOptions.groups);
        summary.put("target_executed", false);
        summary.put("target_bytes_written", false);
        summary.put("evidence_kind", "direct_Ghidra_static_query_not_REA_Evidence");
        summary.put("limitations", List.of(
            "Wrapper must use -process -noanalysis -readOnly; no import or database save is requested.",
            "Selected MIPS PIC t9=entry and optional gp values are explicit ephemeral analysis assumptions, not runtime observations.",
            "Optional standard abort/throw noreturn semantics, selected GOT callsite overrides, and caller-supplied FDE/symbol bounds modify only unsaved analysis metadata; inspect selection-and-context.json.",
            "Only existing exact function entries are selected; no functions, instructions or data are created.",
            "Decompiler opens after context seeding and its cache is flushed before queries.",
            "Existing analyzed xrefs/caller/callee inventories can remain incomplete; no new auto-analysis is run.",
            "Only direct references to already-defined string data are emitted; GOT/pointer indirection can hide strings.",
            "Instruction immediates are candidates, not established resource IDs; PIC address calculations require interpretation.",
            "Pcode constants fold selected arithmetic and reads from analyzed loaded memory; these are static derivations and do not establish runtime argument values.",
            "C++ indirect calls, function boundaries, prototypes and device behavior may remain unresolved."
        ));
        write("summary.json", summary);
        println("UI selection exported " + reports.size() + " existing functions with " + seeds.size() + " ephemeral context seeds");
    }
}
