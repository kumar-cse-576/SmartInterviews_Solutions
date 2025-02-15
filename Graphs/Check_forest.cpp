#include <bits/stdc++.h>
using namespace std;

bool isT(vector<vector<int>>&g,int i,vector<bool>&vi,int p){
    vi[i]=true;
    for(auto it:g[i]){
        if(it==p)continue;
        if(vi[it]==true)return false;
        if(!isT(g,it,vi,i))return false;
    }
    return true;
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
        int s,d;
        cin>>s>>d;
        g[s].push_back(d);
        g[d].push_back(s);
    }
    int flg=true;
    vector<bool> vi(n+1,false);
    for(int i=1;i<=n;i++){
        if(!vi[i]){
            if(!isT(g,i,vi,-1)){
                flg=false;
                break;
            }
        }
    }
    if(flg)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
   }
   
    return 0;
}
