#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
    long n; if(scanf("%ld",&n)!=1) return 0;
    if(n<2){ printf("0\n"); return 0; }
    long m=(n+1)/2; /* odds only: index i -> number 2*i+1 */
    unsigned char *c=(unsigned char*)calloc(m,1);
    if(!c) return 1;
    for(long i=3;i*i<=n;i+=2){
        if(!c[i/2]){
            for(long j=i*i;j<=n;j+=2*i) c[j/2]=1;
        }
    }
    long cnt=1; /* prime 2 */
    for(long i=1;i<m;i++) if(!c[i]) cnt++;
    printf("%ld\n",cnt);
    return 0;
}
