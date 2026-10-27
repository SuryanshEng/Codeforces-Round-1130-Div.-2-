#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int k,root=1,hub=1;
        bool found=false;
        cin>>k;
        for(int i=1;i<=k;i++){
            int n,u,v;
            cin>>n;
            vector<int> kohli(n+1),dhoni(n+1);
            for(int j=1;j<n;j++){
                cin>>u>>v;
                kohli[u]++;kohli[v]++;
                dhoni[u]^=v;dhoni[v]^=u;
            }
            if(n>1&&!found){
                for(int x=1;x<=n;x++)
                    if(kohli[x]==1){root=i;hub=dhoni[x];found=true;break;}
            }
        }
        for(int i=1;i<=k;i++)
            if(i!=root)cout<<i<<" 1 "<<root<<' '<<hub<<'\n';
    }
}