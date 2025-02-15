#include <bits/stdc++.h>
using namespace std;


int dfs(vector<vector<int>>&g,int i,vector<bool>&vi){
    vi[i]=true;
    int v=1;
    for(auto it:g[i]){
        if(vi[it]==false)v+=dfs(g,it,vi);
    }
    return v;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        vector<vector<int>>g(n+1);
        while(e--){
            int e,d;
            cin>>e>>d;
            g[e].push_back(d);
            g[d].push_back(e);
        }
        vector<int> r,pf;
        vector<bool> vi(n+1,false);
        for(int i=1;i<=n;i++){
            if(!vi[i]){
                r.push_back(dfs(g,i,vi));
            }
        }
        pf.resize(r.size());
        int s=0;
        pf[r.size()-1]=r[r.size()-1];
        for(int i=r.size()-2;i>=0;i--){
            pf[i]=pf[i+1]+r[i];
        }
        long long p=0;
        for(int i=0;i<r.size()-1;i++){
            p+=(r[i]*pf[i+1]);
        }
        cout<<p<<endl;
    }
    return 0;
}
