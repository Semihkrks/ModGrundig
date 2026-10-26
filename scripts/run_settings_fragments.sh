#!/bin/sh
# Fresh isolated Ghidra metadata copy, read-only program, no target execution.
set -eu
ROOT=/mnt/c/Users/Semih/Desktop/grundig
export JAVA_HOME=/home/semih/.local/share/grundig-tools/jdk21
export PATH="$JAVA_HOME/bin:$PATH"
GHIDRA=/home/semih/.local/share/grundig-tools/ghidra/ghidra_12.1.4_PUBLIC
if [ "$#" -eq 1 ] && [ "$1" = --validate ]; then
    python3 - <<'PY'
import hashlib,json
from pathlib import Path
root=Path('/mnt/c/Users/Semih/Desktop/grundig')
base=root/'analiz/native/ui-four/settings-fragments'
plan=json.loads((base/'logical-plan.json').read_text())
rawpath=root/'analiz/ui-kod-cagrilari.json'
raw=json.loads(rawpath.read_text())
sha=hashlib.sha256((root/'analiz/dosya-sistemleri-tam/08_APP/bin/dvbt_board').read_bytes()).hexdigest()
assert sha==raw['target_sha256']==plan['target_sha256']
rows=[];all_owned=[];calls_output=[];switches=[];modified=[];warnings=[];all_pcode_sites=set()
for phase in plan['phases']:
    name=phase['id'];run=base/('all_'+name+'_120')
    if not (run/(name+'.json')).exists():run=base/'smoke_boundary60'
    report=json.loads((run/(name+'.json')).read_text())
    changes=json.loads((run/'fragment-metadata-assumptions.json').read_text())
    a=int(phase['start'],16);z=int(phase['end_exclusive'],16);analysis_end=int(report.get('analysis_end_exclusive',phase['end_exclusive']),16)
    owned=[int(x['address'],16) for x in report['original_instructions']]
    assert set(owned)==set(range(a,z,4));all_owned.extend(owned)
    valid=report['fragment_decompile_complete'] and report['high_function_present'] and not report['pcode_addresses_outside_fragment']
    assert valid,name
    selected=[x for x in raw['calls'] if a<=int(x['site'],16)<analysis_end]
    rsites={int(x['site'],16):x for x in selected};psites={int(x['site'],16) for x in report['pcode_calls']}
    all_pcode_sites.update(psites)
    assert psites.issubset(rsites),name
    cpath=run/(name+'.c');cbytes=cpath.read_bytes()
    omitted=[{'site':hex(s),'target_candidate':rsites[s].get('target_name_candidate')} for s in sorted(rsites.keys()-psites)]
    rows.append({'id':name,'run':str(run.relative_to(root)),'natural_start':hex(a),'natural_end_exclusive':hex(z),'analysis_end_exclusive':hex(analysis_end),'owned_original_instruction_count':len(owned),'analysis_extra_prefix_bytes':analysis_end-z,'C_bytes':len(cbytes),'C_sha256':hashlib.sha256(cbytes).hexdigest(),'valid_bounded_fragment_C':valid,'pcode_outside_count':len(report['pcode_addresses_outside_fragment']),'raw_analysis_call_count':len(rsites),'pcode_callsite_count':len(psites),'pcode_calls_are_subset_of_raw_calls':True,'raw_call_sites_not_in_pcode':omitted})
    calls_output.append({'id':name,'natural_start':hex(a),'natural_end_exclusive':hex(z),'analysis_end_exclusive':hex(analysis_end),'calls':selected})
    for change in changes:
        if change.get('fragment')!=name:continue
        if change['kind']=='retained_internal_switch_override':switches.append(change)
        if change['kind']=='external_or_unknown_jump_return_abstraction':modified.append(change['original']['address'])
    logs=(run/'ghidra.log').read_text(errors='replace').splitlines()
    warnings.extend({'id':name,'message':line} for line in logs if ' WARN ' in line)
expected=set(range(0x55b6c0,0x579360,4))
assert len(all_owned)==len(set(all_owned))==len(expected)==30504
assert set(all_owned)==expected
assert len(rows)==plan['phase_count']==12
assert len(switches)==2
assert not {'005664c0','00568648'}.intersection(modified)
rejected=[]
for name in ('entry_position','antenna_initial','source_initial'):
    report=json.loads((base/'smoke60'/(name+'.json')).read_text())
    rejected_valid=report['fragment_decompile_complete'] and report['high_function_present'] and not report['pcode_addresses_outside_fragment']
    assert not rejected_valid
    rejected.append({'id':name,'tool_C_complete':report['fragment_decompile_complete'],'pcode_outside_count':len(report['pcode_addresses_outside_fragment']),'valid_bounded_fragment_C':rejected_valid})
raw_function_sites={int(x['site'],16) for x in raw['calls'] if 0x55b6c0<=int(x['site'],16)<0x579360}
result={'target_sha256_actual':sha,'logical_fragment_count':12,'valid_bounded_fragment_C_count':12,'whole_function_C_complete_count':0,'original_owned_instruction_count':len(all_owned),'original_owned_bytes':len(all_owned)*4,'original_instruction_missing_count':len(expected-set(all_owned)),'original_instruction_overlap_count':len(all_owned)-len(set(all_owned)),'C_bytes_total':sum(x['C_bytes'] for x in rows),'pcode_callsite_count_total':sum(x['pcode_callsite_count'] for x in rows),'pcode_callsite_unique_address_count':len(all_pcode_sites),'raw_function_callsite_count':len(raw_function_sites),'raw_function_calls_missing_all_fragment_pcode':[hex(x) for x in sorted(raw_function_sites-all_pcode_sites)],'retained_internal_switches':switches,'merged_loop_branch_sites_not_overridden':['005664c0','00568648'],'phases':rows,'warnings':warnings,'rejected_initial_smoke':rejected,'target_executed':False,'target_bytes_modified':False,'limitations':['Twelve bounded fragments are analysis artifacts, not whole-function C or semantic equivalence.','Boundary RETURN/CALL_RETURN and next-phase prefix adapters are explicit unsaved metadata abstractions; original conditional branches remain authoritative raw evidence.','Per-fragment pcode totals include duplicated adapter-prefix callsites and are not whole-function call counts.','Dead/unreachable paths, inferred prototypes and decompiler optimization can omit raw callsites from pcode; missing callsites are enumerated without asserting equivalence.','MIPS O32/prototype errors can omit C arguments. Raw call candidates retain static argument evidence.','Warnings about unknown frame-relative addresses are retained; runtime stack/object contents and imported bindings remain unobserved.']}
(base/'fragment-validation.json').write_text(json.dumps(result,indent=2)+'\n')
(base/'fragment-raw-call-candidates.json').write_text(json.dumps({'target_sha256':sha,'source':str(rawpath.relative_to(root)),'phases':calls_output},indent=2)+'\n')
print(json.dumps({k:result[k] for k in ('logical_fragment_count','valid_bounded_fragment_C_count','whole_function_C_complete_count','original_owned_instruction_count','original_owned_bytes','original_instruction_missing_count','original_instruction_overlap_count','C_bytes_total','pcode_callsite_count_total')}))
PY
    exit
fi
if [ "$#" -eq 1 ] && [ "$1" = --compile ]; then
    CLASSES="$ROOT/analiz/native/ui-four/settings-fragments/java-compile"
    mkdir -p "$CLASSES"
    GHIDRA_CP=$(find "$GHIDRA/Ghidra" -name '*.jar' -printf '%p:')
    javac -proc:none -cp "$GHIDRA_CP" -d "$CLASSES" "$ROOT/scripts/ghidra/SettingsFragmentExport.java"
    exit
fi
[ "$#" -eq 4 ] || exit 2
MANIFEST=$1
PHASES=$2
RUN=$3
TIMEOUT=$4
case "$MANIFEST" in /*) ;; *) exit 2 ;; esac
[ -f "$MANIFEST" ] && [ ! -L "$MANIFEST" ] || exit 2
case "$RUN" in ''|*[!a-zA-Z0-9_-]*) exit 2 ;; esac
case "$PHASES" in ''|*[!a-zA-Z0-9_,]*) exit 2 ;; esac
case "$TIMEOUT" in ''|*[!0-9]*) exit 2 ;; esac
[ "$TIMEOUT" -ge 1 ] && [ "$TIMEOUT" -le 120 ] || exit 2
SOURCE=/home/semih/grundig-analysis/ghidra-projects
WORK=/home/semih/grundig-analysis/ui-four/settings-fragments
OUT="$ROOT/analiz/native/ui-four/settings-fragments/$RUN"
mkdir -p "$WORK"
if [ ! -f "$WORK/GrundigBounded.gpr" ]; then
    [ ! -e "$WORK/GrundigBounded.rep" ] || exit 3
    cp -a "$SOURCE/GrundigBounded.rep" "$WORK/GrundigBounded.rep"
    cp -a "$SOURCE/GrundigBounded.gpr" "$WORK/GrundigBounded.gpr"
fi
mkdir -p "$ROOT/analiz/native/ui-four/settings-fragments"
mkdir "$OUT"
cp "$MANIFEST" "$OUT/phase-plan.json"
sha256sum "$ROOT/scripts/ghidra/SettingsFragmentExport.java" "$ROOT/scripts/ghidra/SettingsFillListingGaps.java" > "$OUT/query-scripts.sha256"
"$GHIDRA/support/analyzeHeadless" "$WORK" GrundigBounded \
    -process dvbt_board -noanalysis -readOnly -max-cpu 1 \
    -scriptPath "$ROOT/scripts/ghidra" \
    -preScript SettingsFillListingGaps.java "$OUT" \
    -postScript SettingsFragmentExport.java "$OUT/phase-plan.json" "$OUT" "$PHASES" "$TIMEOUT" \
    -log "$OUT/ghidra.log" > "$OUT/console.log" 2>&1
[ -f "$OUT/summary.json" ]
printf '%s\n' "$OUT"
