#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    vector<int> q;
    int mx=0;
    while(t--){
        int n;
        cin>>n;
        mx=max(mx,n);
        q.push_back(n);
    }
    vector<int>dp(mx+1,0);
        dp[0]=dp[1]=dp[2]=dp[3]=dp[4]=1;
        for(int i=5;i<=mx;i++){
            dp[i]=(dp[i-1]%mod+dp[i-5]%mod)%mod;
        }
        for(int i=0;i<q.size();i++){
            cout<<dp[q[i]]<<" "<<endl;
        }
    return 0;
}
