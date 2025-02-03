#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(6);
        for(int i=0;i<6;i++){
            cin>>a[i];
        }
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            int v=INT_MAX;
            for(int j=1;j<=6&&i-j>=0;j++){
                v=min(v,dp[i-j]+a[j-1]);
            }
            dp[i]=v;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
