#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   vector<int>dp(100001,0);
   dp[0]=1;
   for(int i=1;i<=1e5;i++){
    int v=0;
    for(int j=1;j<=6&&i-j>=0;j++){
        v=(v%mod+dp[i-j]%mod)%mod;
    }
    dp[i]=v;
   }
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
   }
    return 0;
}
