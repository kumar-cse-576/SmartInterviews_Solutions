#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> m(2,vector<int>(n));
        for(int i=0;i<2;i++)
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        vector<vector<int>> dp(2,vector<int>(n+1,0));
        dp[0][0]=m[0][0],dp[1][0]=m[1][0];
        for(int i=1;i<=n;i++)
            for(int j=0;j<2;j++)
                if(i!=n) dp[j][i]=m[j][i]+min(dp[j][i-1],k+dp[(j+1)%2][i-1]);
                else dp[j][i]=min(dp[j][i-1],dp[(j+1)%2][i-1]);
         
        cout<<dp[1][n]<<endl;
    }
    return 0;
}
