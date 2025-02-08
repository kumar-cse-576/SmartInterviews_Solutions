#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int s,n;
        cin>>s>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            int sp,cs;
            cin>>sp>>cs;
           a[i]=sp,b[i]=cs;
        }
        vector<vector<int>> dp(n,vector<int>(s+1,0));
        for(int i=0;i<=s;i++){
            if(i>=a[0])dp[0][i]=b[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=s;j++){
                dp[i][j]=dp[i-1][j];
                if(j>=a[i]){
                    dp[i][j]=max(dp[i][j],b[i]+dp[i-1][j-a[i]]);
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<=s;j++){
                mx=max(mx,dp[i][j]);
            }
        }
        cout<<mx<<endl;

    }
    return 0;
}
