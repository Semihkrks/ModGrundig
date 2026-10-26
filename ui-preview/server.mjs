import http from 'node:http';
import {readFile,realpath,stat} from 'node:fs/promises';
import {fileURLToPath} from 'node:url';
import path from 'node:path';
const base=path.dirname(fileURLToPath(import.meta.url));
const types={'.html':'text/html; charset=utf-8','.js':'text/javascript; charset=utf-8','.css':'text/css; charset=utf-8','.svg':'image/svg+xml','.png':'image/png','.json':'application/json; charset=utf-8','.ttf':'font/ttf','.otf':'font/otf'};
const server=http.createServer(async(req,res)=>{
  try{
    if(!['GET','HEAD'].includes(req.method)){res.writeHead(405).end();return;}
    const raw=decodeURIComponent(new URL(req.url,'http://localhost').pathname);
    const relative=raw==='/'?'index.html':raw.replace(/^\/+/, '');
    if(relative.split(/[\\/]/).some(part=>part==='..'||part.startsWith('.'))){res.writeHead(403).end();return;}
    const file=await realpath(path.resolve(base,relative));
    if(!file.startsWith(base+path.sep)||!(await stat(file)).isFile()){res.writeHead(403).end();return;}
    if(!types[path.extname(file)]){res.writeHead(403).end();return;}
    const data=await readFile(file);
    res.writeHead(200,{'Content-Type':types[path.extname(file)],'Cache-Control':'no-store','X-Content-Type-Options':'nosniff','Content-Security-Policy':"default-src 'self'; img-src 'self' data:; style-src 'self' 'unsafe-inline'; script-src 'self'; connect-src 'self'; base-uri 'none'; frame-ancestors 'none'"});
    res.end(req.method==='HEAD'?undefined:data);
  }catch{res.writeHead(404).end('Bulunamadı');}
});
server.listen(Number(process.env.PORT)||4173,'127.0.0.1',()=>console.log('ModGrundig offline preview: http://127.0.0.1:4173'));
