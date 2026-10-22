#!/usr/bin/env python3
"""Export indexed UBIFS metadata without extracting files or reading data nodes.

Run with the installed ubi-reader Python, e.g.:
  python -B scripts/export_ubifs_metadata.py --images /path/to/images \
    --output analiz/ubifs-orijinal-metadata.json

The stock walk.index reads DATA/XENT bodies. This independent bounded traversal
uses the same public node parsers but deliberately skips those bodies. It does
not replay the journal, decrypt names, resolve symlinks, or create device nodes.
"""

import argparse
from collections import Counter, defaultdict
from contextlib import redirect_stdout
import importlib.metadata
import io
import json
import os
from pathlib import Path
import stat
import struct
import zlib

from ubireader.ubi_io import ubi_file
from ubireader.ubifs import ubifs, nodes
from ubireader.ubifs import defines as D


IMAGE_NAMES = (
    "06_RFS.bin", "07_MSLIB.bin", "08_APP.bin", "09_CONFIG.bin",
    "10_customer.bin", "11_customer_update.bin", "12_certificate.bin",
    "13_oad.bin",
)
TYPE_NAMES = {
    stat.S_IFREG: "regular", stat.S_IFDIR: "directory",
    stat.S_IFLNK: "symlink", stat.S_IFCHR: "character_device",
    stat.S_IFBLK: "block_device", stat.S_IFIFO: "fifo",
    stat.S_IFSOCK: "socket",
}


def inspect_image(path):
    """Read the committed index; all paths remain inert POSIX strings."""
    source_stat = path.lstat()
    if not stat.S_ISREG(source_stat.st_mode):
        raise ValueError("Image must be a regular file, not a symlink")
    result = {
        "image": path.name, "source_path": str(path),
        "source_size": source_stat.st_size, "entries": [], "issues": [],
        "scope": "committed_master_index_only_no_journal_replay",
        "filesystem_empty_verdict": "unknown",
    }
    issues = result["issues"]
    diagnostics = io.StringIO()
    image_file = ubi_file(str(path), 1)
    try:
        # Constructor only parses superblock/master/padding metadata.
        with redirect_stdout(diagnostics):
            filesystem = ubifs(image_file)
        master = filesystem.master_node
        if master is None:
            raise ValueError("No selected master node")
        result["superblock"] = {
            k: getattr(filesystem.superblock_node, k)
            for k in ("leb_size", "min_io_size", "leb_cnt", "flags", "fmt_version")
        }
        result["selected_master"] = {
            k: getattr(master, k)
            for k in ("cmt_no", "root_lnum", "root_offs", "root_len")
        }
        if filesystem.superblock_node.flags & D.UBIFS_FLG_ENCRYPTION:
            result["status"] = "encrypted_names_not_decoded"
            issues.append({"kind": "encrypted_filesystem_names_out_of_scope"})
            return result

        size, leb = source_stat.st_size, filesystem.leb_size
        counters = Counter()
        inodes, dents = {}, defaultdict(list)
        pending = [(master.root_lnum, master.root_offs, master.root_len)]
        visited = set()

        def read_at(offset, length, purpose):
            if offset < 0 or length < 0 or offset + length > size:
                raise ValueError("Metadata read outside image")
            image_file.seek(offset)
            data = image_file.read(length)
            if len(data) != length:
                raise ValueError("Short metadata read")
            counters["read_bytes_" + purpose] += length
            return data

        def check_crc(header_bytes, body, header, location):
            if len(body) + D.UBIFS_COMMON_HDR_SZ != header.len:
                counters["crc_unchecked_excluded_inline_or_padding"] += 1
                return
            actual = (~zlib.crc32(header_bytes[8:] + body)) & 0xFFFFFFFF
            counters["metadata_crc_checked"] += 1
            if actual != header.crc:
                raise ValueError("Metadata CRC mismatch at " + hex(location))

        max_nodes = size // D.UBIFS_COMMON_HDR_SZ + 1
        while pending:
            lnum, offset, expected_length = pending.pop()
            location = lnum * leb + offset
            if (lnum, offset) in visited:
                issues.append({"kind": "repeated_index_address_skipped", "offset": location})
                continue
            if lnum < 0 or offset < 0 or offset >= leb or len(visited) >= max_nodes:
                raise ValueError("Invalid/cyclic/excessive index traversal")
            visited.add((lnum, offset))
            raw_header = read_at(location, D.UBIFS_COMMON_HDR_SZ, "common_headers")
            header = nodes.common_hdr(raw_header)
            if header.magic != 0x06101831:
                raise ValueError("Invalid UBIFS magic at " + hex(location))
            if not D.UBIFS_COMMON_HDR_SZ <= header.len <= leb - offset:
                raise ValueError("Invalid node length at " + hex(location))
            if location + header.len > size or header.len != expected_length:
                raise ValueError("Index branch/node length mismatch or out-of-image node")
            body_at = location + D.UBIFS_COMMON_HDR_SZ
            body_length = header.len - D.UBIFS_COMMON_HDR_SZ
            counters["node_type_" + str(header.node_type)] += 1

            if header.node_type in (D.UBIFS_DATA_NODE, D.UBIFS_XENT_NODE):
                category = "regular_data" if header.node_type == D.UBIFS_DATA_NODE else "xent"
                counters["skipped_body_bytes_" + category] += body_length
                continue
            if header.node_type == D.UBIFS_IDX_NODE:
                body = read_at(body_at, body_length, "index")
                check_crc(raw_header, body, header, location)
                child_count, _ = struct.unpack_from("<HH", body)
                if not child_count:
                    issues.append({"kind": "zero_child_index", "offset": location})
                    continue
                index = nodes.idx_node(body)
                pending.extend((b.lnum, b.offs, b.len) for b in reversed(index.branches))
            elif header.node_type == D.UBIFS_INO_NODE:
                if body_length < D.UBIFS_INO_NODE_SZ:
                    raise ValueError("Truncated inode metadata")
                fixed = read_at(body_at, D.UBIFS_INO_NODE_SZ, "inode_fixed")
                inode = nodes.ino_node(fixed)
                if not 0 <= inode.data_len <= body_length - D.UBIFS_INO_NODE_SZ:
                    raise ValueError("Invalid inline metadata size")
                row = {k: getattr(inode, k) for k in (
                    "mode", "uid", "gid", "size", "nlink", "mtime_sec", "mtime_nsec",
                )}
                row.update(inum=inode.key["ino_num"], mode_octal=oct(inode.mode),
                           permissions_octal=format(stat.S_IMODE(inode.mode), "04o"),
                           type=TYPE_NAMES.get(stat.S_IFMT(inode.mode), "unknown"),
                           inode_node_offset=location)
                body = fixed
                if row["type"] in ("symlink", "character_device", "block_device"):
                    if inode.data_len > 4096:
                        raise ValueError("Excessive symlink/device inline metadata")
                    inline = read_at(body_at + D.UBIFS_INO_NODE_SZ, inode.data_len, "link_device_inline")
                    body += inline
                    if row["type"] == "symlink":
                        row["symlink_target"] = inline.decode("utf-8", "surrogateescape")
                    elif len(inline) in (4, 8):
                        encoded = struct.unpack_from("<I", inline)[0]
                        row["device"] = {
                            "encoding": "linux_new_encode_dev_u32_le",
                            "major": (encoded >> 8) & 0xFFF,
                            "minor": (encoded & 0xFF) | ((encoded >> 12) & 0xFFF00),
                        }
                    else:
                        issues.append({"kind": "unsupported_device_descriptor_length", "inum": row["inum"]})
                else:
                    counters["skipped_normal_inode_inline_bytes"] += inode.data_len
                check_crc(raw_header, body, header, location)
                if row["inum"] in inodes:
                    raise ValueError("Duplicate live indexed inode")
                inodes[row["inum"]] = row
            elif header.node_type == D.UBIFS_DENT_NODE:
                body = read_at(body_at, body_length, "directory_entries")
                check_crc(raw_header, body, header, location)
                dent = nodes.dent_node(body)
                if not 0 < dent.nlen <= 255 or len(dent.raw_name) != dent.nlen:
                    raise ValueError("Invalid directory entry name length")
                name = dent.raw_name.decode("utf-8", "surrogateescape")
                if name in (".", "..") or any(c in name for c in ("/", "\\", "\0")):
                    issues.append({"kind": "unsafe_directory_name_skipped", "offset": location})
                    continue
                if dent.inum:
                    dents[dent.key["ino_num"]].append((name, dent.inum))
            else:
                issues.append({"kind": "unsupported_indexed_node_type", "type": header.node_type, "offset": location})

        root = inodes.get(D.UBIFS_ROOT_INO)
        reached, seen_paths = set(), set()
        paths = [("/", D.UBIFS_ROOT_INO, frozenset())] if root else []
        while paths:
            path_string, inum, ancestors = paths.pop()
            if inum not in inodes:
                issues.append({"kind": "dent_missing_inode", "path": path_string, "inum": inum})
                continue
            if path_string in seen_paths or len(seen_paths) > 1000000:
                raise ValueError("Repeated/excessive output path")
            seen_paths.add(path_string)
            row = dict(inodes[inum], path=path_string)
            result["entries"].append(row)
            reached.add(inum)
            if row["type"] == "directory":
                if inum in ancestors or len(ancestors) > 1024:
                    issues.append({"kind": "directory_cycle_or_depth_limit", "path": path_string})
                    continue
                ancestry = ancestors | {inum}
                for name, child in sorted(dents.get(inum, []), reverse=True):
                    paths.append((path_string.rstrip("/") + "/" + name, child, ancestry))

        result["entries"].sort(key=lambda row: row["path"])
        result["indexed_inode_count"] = len(inodes)
        result["reachable_inode_count"] = len(reached)
        result["unreachable_indexed_inode_count"] = len(inodes.keys() - reached)
        result["type_counts"] = dict(sorted(Counter(r["type"] for r in result["entries"]).items()))
        result["read_accounting"] = dict(sorted(counters.items()))
        result["normal_file_data_payload_bytes_read"] = 0
        result["xent_body_bytes_read"] = 0
        if not root:
            result["status"] = "root_inode_not_observed_unknown"
        elif len(result["entries"]) == 1:
            result["status"] = "root_only_index_no_directory_entries_empty_verdict_unknown"
        else:
            result["status"] = "indexed_metadata_exported" if not issues else "indexed_metadata_exported_with_gaps"
        return result
    finally:
        result["parser_diagnostics"] = diagnostics.getvalue().splitlines()
        image_file.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--images", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    output = {
        "schema_version": 1, "tool": "export_ubifs_metadata.py",
        "ubi_reader_version": importlib.metadata.version("ubi-reader"),
        "scope": "Original committed UBIFS inode/dentry metadata; no file extraction",
        "limitations": [
            "No journal replay or live-device observation; indexed snapshot only.",
            "Regular DATA nodes and XENT bodies are skipped, not hashed or decoded.",
            "Normal inode inline data/xattr values are not read or exported.",
            "Symlink targets are inert text; no host symlink resolution or device creation.",
            "CRC is checked only when all metadata bytes of a node may be read.",
            "Missing/root-only indexed inodes do not prove an empty OAD filesystem.",
        ],
        "images": [],
    }
    for name in IMAGE_NAMES:
        output["images"].append(inspect_image(args.images / name))
    # One caller-selected JSON output is the only filesystem mutation.
    with args.output.open("w", encoding="utf-8", newline="\n") as stream:
        json.dump(output, stream, ensure_ascii=True, indent=2)
        stream.write("\n")
    print(json.dumps({"output": str(args.output), "images": [
        {"image": item["image"], "status": item["status"],
         "counts": item.get("type_counts", {}), "issues": len(item["issues"])}
        for item in output["images"]
    ]}))


if __name__ == "__main__":
    main()
