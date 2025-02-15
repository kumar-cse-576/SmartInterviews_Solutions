#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&g,int s,vector<bool> &vi){
    vi[s]=true;
    for(auto it:g[s]){
        if(!vi[it])dfs(g,it,vi);
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
    vector<vector<int>> g(n+1);
    for(int i=0;i<d;i++){
        int s,m;
        cin>>s>>m;
        g[s].push_back(m);
        g[m].push_back(s);
    }
    int cp=0;
    vector<bool>vi(n+1,false);
    for(int i=1;i<=n;i++){
        if(vi[i]==false){
            cp++;
            dfs(g,i,vi);
        }
    }
    cout<<cp<<endl;
    
    }
    return 0;
}
