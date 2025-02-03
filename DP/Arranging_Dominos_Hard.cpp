#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   
   int mx=1e6+1;
    vector<long long int> dp(mx,0);
    dp[0]=1;dp[1]=1;
    for(long long int i=2;i<mx;i++){
        dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        if(i<5)continue;
        dp[i]=(dp[i]%mod+(((dp[i-5]%mod)*(8))%mod)%mod)%mod;
    }
   int t;
   cin>>t;
   while(t--){
    int n;cin>>n;
    cout<<dp[n]<<endl;
   }
  return 0;
}
