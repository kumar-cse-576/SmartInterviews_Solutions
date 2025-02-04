#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][a[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i]){
                    dp[i][j]=dp[i][j]||dp[i-1][j-a[i]];
                }
            }
        }
        if(dp[n-1][k])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
