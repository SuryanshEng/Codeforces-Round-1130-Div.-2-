#include <bits/stdc++.h>
using namespace std;
int val(vector<int>&a,int k){
    int n=a.size();
    vector<int> f(n),seen(n+2,0);
    int m=0;
    for(int i=0;i<n;i++){
        seen[a[i]]=1;
        while(seen[m]) m++;
        f[i]=m;
    }
    sort(f.rbegin(),f.rend());
    return f[k-1];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> a(n);
        for(auto&x:a) cin>>x;
        int best=val(a,k),bi=-1,bj=-1;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                swap(a[i],a[j]);
                int v=val(a,k);
                swap(a[i],a[j]);
                if(v>best){best=v;bi=i+1;bj=j+1;}
            }
        if(bi<0) cout<<-1<<"\n";
        else cout<<bi<<" "<<bj<<"\n";
    }
}   shorten,concise and optimize this code even further