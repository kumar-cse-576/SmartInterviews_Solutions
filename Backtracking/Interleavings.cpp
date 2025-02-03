#include <bits/stdc++.h>
using namespace std;

void f(string a,string b,int i,int j,string r,vector<string>&res){
    if(i==a.size()){
        while(j<b.size())r+=b[j++];
        res.push_back(r);
        return;
    }
    if(j==b.size()){
        while(i<a.size())r+=a[i++];
        res.push_back(r);
        return;
    }
    if(a[i]<b[j]){f(a,b,i+1,j,r+a[i],res);f(a,b,i,j+1,r+b[j],res);}
    else {f(a,b,i,j+1,r+b[j],res);f(a,b,i+1,j,r+a[i],res);}
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        string a,b,r="";
        cin>>a>>b;
        vector<string> res;
        if(a[0]<b[0]){f(a,b,1,0,r+a[0],res);
        f(a,b,0,1,r+b[0],res);}
        else{
           f(a,b,0,1,r+b[0],res); 
           f(a,b,1,0,r+a[0],res);
        }
        cout<<"Case #"<<i<<":"<<endl;
        for(auto it:res){
            cout<<it<<endl;
        }
    }
    return 0;
}
