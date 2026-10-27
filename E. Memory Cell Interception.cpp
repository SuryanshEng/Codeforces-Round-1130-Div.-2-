#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(const string&x,const string&y){
    int m=y.size();
    vector<int> w;
    for(int i=0;i<m;i++)
        if(y[i]=='W')w.push_back(i+1);
    vector<long long> g;
    for(size_t k=0;k+1<w.size();k++)g.push_back(w[k+1]-w[k]);
    sort(g.begin(),g.end());
    vector<long long> pre(g.size()+1,0);
    for(size_t k=0;k<g.size();k++)pre[k+1]=pre[k]+g[k];
    vector<int> nxt(m+2,0);
    for(int p=m;p>=1;p--)nxt[p]=y[p-1]=='W'?p:nxt[p+1];
    vector<long long> res;
    int a=0;
    for(int i=1;i<=(int)x.size();i++){
        if(x[i-1]=='W'){
            a=i;
            continue;
        }
        long long L=i-a,r;
        if(a==0){
            r=1;
            if(!w.empty()){
                int id=lower_bound(g.begin(),g.end(),L)-g.begin();
                r+=pre[id]+L*(long long)(g.size()-id)+L;
            }
        }else{
            r=m+1;
            if(!w.empty()){
                long long lo=max(1LL,m-L+2);
                if(lo<=m&&nxt[lo]){
                    long long bf=nxt[lo],bl=w.back();
                    r+=max(0LL,bl+i-1-max((long long)a+m,bf+a-1));
                }
            }
        }
        res.push_back(r);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string s,u;
        cin>>n>>m>>s>>u;
        for(auto*p:{&s,&u}){
            auto r=p==&s?solve(s,u):solve(u,s);
            for(size_t i=0;i<r.size();i++)cout<<r[i]<<(i+1<r.size()?" ":"");
            cout<<"\n";
        }
    }
}