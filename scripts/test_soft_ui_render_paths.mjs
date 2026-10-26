import test from'node:test';import assert from'node:assert/strict';import fs from'node:fs/promises';
import{validateRenderPlan}from'./render_soft_ui_assets.mjs';
const plan=JSON.parse(await fs.readFile(new URL('../ui-assets/build-plan.json',import.meta.url),'utf8'));
test('valid render plan passes without rendering',async()=>{await validateRenderPlan(plan);});
test('traversal and source alias rejected BEFORE output writes',async()=>{
  for(const [field,value]of [['rendered','ui-assets/rendered/../../README.md'],['source','ui-assets/sources/../../README.md'],['rendered',plan.assets[0].original_path]]){
    const changed=structuredClone(plan);changed.assets[0][field]=value;await assert.rejects(validateRenderPlan(changed));
  }
});
