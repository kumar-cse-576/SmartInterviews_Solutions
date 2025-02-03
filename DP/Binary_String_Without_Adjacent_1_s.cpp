#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
   int mx=1e5;
   vector<vector<int>>dp(mx+1,vector<int>(2,0));
   dp[0][0]=1;
   dp[0][1]=1;
   for(int i=1;i<=mx;i++){
    dp[i][0]=(dp[i-1][0]%mod+dp[i-1][1]%mod)%mod;
    dp[i][1]=dp[i-1][0]%mod;
   } 
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    cout<<(dp[n-1][0]%mod+dp[n-1][1]%mod)%mod<<endl;
   }
    return 0;
}
