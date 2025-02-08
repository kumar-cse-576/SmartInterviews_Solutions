#include <bits/stdc++.h>
using namespace std;
const long long int mod=1000000007;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int t;
    cin>>t;
    int n,r;
    n=r=2000;
    vector<vector<int>> dp(r+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<=r;i++){
            for(int j=i;j<=n;j++){
                dp[i][j]=(dp[i][j-1]%mod+dp[i-1][j-1]%mod)%mod;
            }
        }
    while(t--){
       int p,q;
       cin>>p>>q;
        cout<<dp[q][p]<<" "<<endl;
    }
    return 0;
}
