#include <bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>>&g,int i,vector<bool>&vi,vector<bool>&rvi){
    vi[i]=true;
    rvi[i]=true;
    for(auto it:g[i]){
         if(!vi[it]&&f(g,it,vi,rvi))return true;
        if(rvi[it])return true;
    }
    rvi[i]=false;
    return false;
}

int main() {
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
    }
vector<bool> vi(n+1,false),rvi(n+1,false);
int st=0;
bool flg=false;
for(int i=0;i<g.size();i++){
    if(!vi[i])flg=flg||f(g,i,vi,rvi);
}
if(flg){
    cout<<"True"<<endl;
}else{
    cout<<"False"<<endl;
}
    }
    
    return 0;
}
