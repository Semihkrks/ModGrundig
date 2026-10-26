// Rasterize NEW SVG sources only. Never reads/writes extracted firmware assets.
import fs from 'node:fs/promises';
import path from 'node:path';
import { fileURLToPath, pathToFileURL } from 'node:url';
import { createRequire } from 'node:module';

const root = path.resolve(path.dirname(fileURLToPath(import.meta.url)), '..');
const require = createRequire(import.meta.url);
const playwrightPath = process.env.SOFT_UI_PLAYWRIGHT || 'C:/Users/Semih/.cache/codex-runtimes/codex-primary-runtime/dependencies/node/node_modules/playwright';
const playwright = require(playwrightPath);
const chrome = process.env.SOFT_UI_CHROME || 'C:/Program Files/Google/Chrome/Application/chrome.exe';
async function contained(file,base,existing=false){
  const wanted=path.resolve(root,file),allowed=await fs.realpath(path.resolve(root,base));
  const relative=path.relative(allowed,wanted);
  if(!relative||relative.startsWith('..')||path.isAbsolute(relative))throw new Error('Output escapes allowed root');
  let cursor=wanted;
  while(true){try{cursor=await fs.realpath(cursor);break;}catch(error){if(error.code!=='ENOENT')throw error;const next=path.dirname(cursor);if(next===cursor)throw error;cursor=next;}}
  const actual=path.relative(allowed,cursor);
  if(actual.startsWith('..')||path.isAbsolute(actual))throw new Error('Symlink escapes allowed root');
  if(existing)await fs.access(wanted);
  return wanted;
}
export async function validateRenderPlan(plan){
  if(!Array.isArray(plan.assets)||plan.assets.length!==19)throw new Error('Expected 19 assets');
  const targets=new Set();
  for(const a of plan.assets){
    if(!/^[a-z0-9-]+$/.test(a.key)||a.source!==`ui-assets/sources/${a.key}.svg`||a.rendered!==`ui-assets/rendered/${a.key}.png`)throw new Error('Unexpected asset path');
    await contained(a.source,'ui-assets/sources',true);
    const target=await contained(a.rendered,'ui-assets/rendered');
    if(targets.has(target))throw new Error('Duplicate output');targets.add(target);
    const {width,height}=a.original_geometry;
    if(!Number.isInteger(width)||!Number.isInteger(height)||width<1||height<1||width>4096||height>4096)throw new Error('Unexpected geometry');
  }
  await contained('ui-assets/render-environment.json','ui-assets');
}
async function main(){
const plan = JSON.parse(await fs.readFile(path.join(root, 'ui-assets/build-plan.json'), 'utf8'));
await validateRenderPlan(plan); // preflight EVERY destination before opening a browser or writing.
const browser = await playwright.chromium.launch({ executablePath: chrome, headless: true });
try {
  const page = await browser.newPage({ deviceScaleFactor: 1 });
  for (const asset of plan.assets) {
    const { width, height } = asset.original_geometry;
    await page.setViewportSize({ width, height });
    await page.goto(pathToFileURL(path.join(root, asset.source)).href);
    await fs.mkdir(path.dirname(path.join(root, asset.rendered)), { recursive: true });
    await contained(asset.rendered,'ui-assets/rendered');
    await page.screenshot({ path: path.join(root, asset.rendered), omitBackground: true, animations: 'disabled' });
  }
  await fs.writeFile(path.join(root, 'ui-assets/render-environment.json'), JSON.stringify({ browser: await browser.version(), playwright: require(path.join(playwrightPath, 'package.json')).version, scale: 1, assets: plan.assets.length }, null, 2) + '\n');
  console.log(`Rendered ${plan.assets.length} new SVGs`);
} finally {
  await browser.close();
}
}
if(process.argv[1]&&path.resolve(process.argv[1])===fileURLToPath(import.meta.url))await main();
