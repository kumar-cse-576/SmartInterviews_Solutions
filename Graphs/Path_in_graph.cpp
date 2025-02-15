#include <bits/stdc++.h>
using namespace std;


bool isc(int s,int d,vector<vector<int>> &ad){
    vector<bool> vi(ad.size(),false);
    queue<int> q;
    q.push(s);
    vi[s]=true;
    while(!q.empty()){
            int c=q.front();
            q.pop();
            for(auto it:ad[c]){
                if(vi[it]!=true){
                     if(it==d)return true;
                    vi[it]=true;
                    q.push(it);
                }
             }
    }
    return false;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Test Case #"<<i<<":"<<endl;
        int n,e;
        cin>>n>>e;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<e;i++){
            int s,d;
            cin>>s>>d;
            adj[s].push_back(d);
            adj[d].push_back(s);
        }
        int q;
        cin>>q;
        while(q--){
            int s,d;
            cin>>s>>d;
            if((s==d)||(!adj[s].empty()&&isc(s,d,adj))){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
