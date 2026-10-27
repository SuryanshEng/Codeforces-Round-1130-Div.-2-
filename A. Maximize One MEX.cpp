#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        vector<int> a(n),c(n+2);
        for(int&x:a) scanf("%d",&x);
        int p=n-k+1,m=0,i=-1,j=-1;
        for(int x=0;x<p;x++) c[a[x]]++;
        while(c[m]) m++;
        for(int x=p;x<n&&j<0;x++) if(a[x]==m) j=x;
        for(int x=0;x<p&&i<0;x++) if(c[a[x]]>1||a[x]>m) i=x;
        if(i<0||j<0) puts("-1");
        else printf("%d %d\n",i+1,j+1);
    }
}