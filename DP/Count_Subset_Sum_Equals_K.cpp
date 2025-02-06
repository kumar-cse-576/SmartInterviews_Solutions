#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        dp[0][a[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i]){
                    dp[i][j]=(((dp[i][j]%mod)+(dp[i-1][j-a[i]]%mod))%mod);
                }
            }
        }
        cout<<dp[n-1][k]<<endl;
    }
    return 0;
}
