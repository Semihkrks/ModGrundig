// Export loader address/relocation metadata from existing read-only projects.
// @category Grundig
import ghidra.app.script.GhidraScript;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.reloc.*;
import com.google.gson.*;
import java.nio.file.*;
import java.io.*;
import java.util.*;

public class ExportProgramMemory extends GhidraScript {
    @Override public void run() throws Exception {
        String sha=currentProgram.getExecutableSHA256();
        Path out=Paths.get(getScriptArgs()[0]).resolve(sha.toLowerCase());
        if(!Files.isDirectory(out))throw new IllegalStateException("Expected prior index directory");
        List<Map<String,Object>> blocks=new ArrayList<>();
        for(MemoryBlock b:currentProgram.getMemory().getBlocks())blocks.add(Map.of(
            "name",b.getName(),"start",b.getStart().toString(),"end",b.getEnd().toString(),
            "bytes",b.getSize(),"initialized",b.isInitialized(),"read",b.isRead(),"write",b.isWrite(),"execute",b.isExecute()));
        Map<String,Long> statuses=new TreeMap<>();long relocations=0;
        Gson gson=new GsonBuilder().disableHtmlEscaping().create();
        try(Writer w=Files.newBufferedWriter(out.resolve("relocations.jsonl"))) {
            Iterator<Relocation> it=currentProgram.getRelocationTable().getRelocations();
            while(it.hasNext()) {
                Relocation r=it.next();String status=r.getStatus().toString();
                Map<String,Object> row=new LinkedHashMap<>();
                row.put("address",r.getAddress().toString());row.put("status",status);row.put("type",r.getType());row.put("symbol",r.getSymbolName());
                gson.toJson(row,w);w.write("\n");statuses.merge(status,1L,Long::sum);relocations++;
            }
        }
        Map<String,Object> meta=new LinkedHashMap<>();meta.put("sha256",sha);meta.put("program",currentProgram.getName());
        meta.put("image_base",currentProgram.getImageBase().toString());meta.put("blocks",blocks);
        meta.put("relocation_count",relocations);meta.put("relocation_status_counts",statuses);
        meta.put("firmware_modified",false);meta.put("target_executed",false);
        Files.writeString(out.resolve("memory-and-loader.json"),new GsonBuilder().setPrettyPrinting().create().toJson(meta));
    }
}
