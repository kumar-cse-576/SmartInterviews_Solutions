#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> q(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>q[i][0]>>q[i][1];
        }
        vector<int> dp(n,0);
        dp[n-1]=q[n-1][0];
        for(int i=n-2;i>=0;i--){
            int mx=q[i][0];
            if(1+q[i][1]+i<n)
                mx+=dp[1+q[i][1]+i];
            dp[i]=max(mx,dp[i+1]);
        }
        cout<<dp[0]<<endl;
    }
     return 0;
}
