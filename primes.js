// Node fallback: odd-only sieve with Uint8Array
const fs=require('fs');
const n=parseInt(fs.readFileSync(0,'utf8').trim(),10);
if(n<2){console.log(0);process.exit(0);}
const m=(n+1)>>1, c=new Uint8Array(m);
for(let i=3;i*i<=n;i+=2) if(!c[i>>1]) for(let j=i*i;j<=n;j+=2*i) c[j>>1]=1;
let cnt=1; for(let i=1;i<m;i++) if(!c[i]) cnt++;
console.log(cnt);
