#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        vector<int> a(n),q(n+1,n);
        for(int x=0;x<n;x++) scanf("%d",&a[x]),q[a[x]]=x;
        int p=n-k+1,m=0;
        while(q[m]<p) m++;
        if(m==p) puts("-1");
        else printf("%d %d\n",int(max_element(a.begin(),a.begin()+p)-a.begin())+1,q[m]+1);
    }
}