#include <bits/stdc++.h>
using namespace std;

bool canIplace(vector<vector<int>>&q,int i,int j,vector<int>&plc){
    if(plc.empty())return true;
    for(int ii=0;ii<plc.size();ii++){
        if(plc[ii]==j)return false;
    }
    
    for(int ii=0;ii<plc.size();ii++){
        if(abs(ii-i)==abs(j-plc[ii]))return false;
    }
    return true;
}

void nq(int i,vector<vector<int>>q,vector<int>&plc,int &nos){
    if(i==q.size()){
        
        nos++;
        for(int ii=0;ii<q.size();ii++){
            for(int jj=0;jj<q[0].size();jj++){
                cout<<q[ii][jj];
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    for(int j=0;j<q[0].size();j++){
        if(!canIplace(q,i,j,plc))continue;
        q[i][j]=1;
        plc.push_back(j);
        nq(i+1,q,plc,nos);
        plc.pop_back();
        q[i][j]=0;
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> q(n,vector<int>(n));
        vector<int> plc;
        int nos=0;
        nq(0,q,plc,nos);
        if(nos==0)cout<<-1<<endl<<endl;
    }
    return 0;
}
