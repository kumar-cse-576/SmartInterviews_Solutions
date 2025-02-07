#include <bits/stdc++.h>
using namespace std;
const long long mod=1000000007;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,m,b;
        cin>>n>>m>>b;
        vector<vector<int>> a(n,vector<int>(m,0));
        while(b--){
            int i,j;
            cin>>i>>j;
            a[i][j]=-1;
        }
        if(a[n-1][m-1]==-1){
            cout<<0<<endl;continue;
        }
       vector<vector<long long int>>dp(n,vector<long long>(m,0));
       dp[n-1][m-1]=1;
       for(int i=n-2;i>=0;i--){
        if(a[i][m-1]!=-1)dp[i][m-1]=dp[i+1][m-1];
        else dp[i][m-1]=0;
       }
    for(int i=m-2;i>=0;i--){
        if(a[n-1][i]!=-1)dp[n-1][i]=dp[n-1][i+1];
        else dp[n-1][i]=0;
       }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(a[i][j]==-1)dp[i][j]=0;
                else{
                    dp[i][j]=(dp[i+1][j]%mod+dp[i][j+1]%mod)%mod;
                    dp[i][j]=(dp[i][j]%mod+dp[i+1][j+1]%mod)%mod;
                }
            }
        }
        cout<<dp[0][0]<<endl;
    }
    return 0;
}
