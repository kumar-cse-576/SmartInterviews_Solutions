#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long int fac(int n,vector<long long int>&f){
    if(n==0||n==1)return 1;
    if(f[n]!=0)return f[n];
    return f[n]=((n%mod)*(fac(n-1,f)%mod))%mod;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,mx=0;
    cin>>t;
     vector<int> q(t);
   for(int i=0;i<t;i++){
    cin>>q[i];
    mx=max(q[i],mx);
   }
   vector<long long int> fc(mx+1);
    for(int i=0;i<t;i++){
        cout<<fac(q[i],fc)<<endl;
    }
    return 0;
}
