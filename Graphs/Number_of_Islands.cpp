#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>&g,int i,int j){
    int r=g.size(),c=g[0].size();
    g[i][j]=0;
    if(i>0){
        if(j>0&&g[i-1][j-1])dfs(g,i-1,j-1);
        if(g[i-1][j])dfs(g,i-1,j);
        if(j<c-1&&g[i-1][j+1])dfs(g,i-1,j+1);
    }
    if(j>0&&g[i][j-1])dfs(g,i,j-1);
    if(j<c-1&&g[i][j+1])dfs(g,i,j+1);
    if(i<r-1){
        if(j>0&&g[i+1][j-1])dfs(g,i+1,j-1);
        if(g[i+1][j])dfs(g,i+1,j);
        if(j<c-1&&g[i+1][j+1])dfs(g,i+1,j+1);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int t;
   cin>>t;
   while(t--){
        int r,c;
        cin>>r>>c;
        vector<vector<int>> m(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            string s;
            cin>>s;
            for(int j=0;j<c;j++){
                m[i][j]=s[j]-'0';
            }
        }
        int cp=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]==1){                  
                      cp++;
                    dfs(m,i,j);
                }
            }
        }
        cout<<cp<<endl;
   }
   
   
    return 0;
}
