#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(3,vector<int>(n,0));
        for(int i=0;i<3;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        vector<vector<int>>dp(4,vector<int>(n,0));
        for(int j=0;j<3;j++){
            dp[j][0]=a[j][0];
        }
      for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            int mn=INT_MAX;
            for(int k=0;k<3;k++){
                if(k!=j)mn=min(mn,dp[k][i-1]);
            }
            dp[j][i]=a[j][i]+mn;
        }
      }
         int mn=INT_MAX;
         for(int l=0;l<3;l++)
        mn=min(mn,dp[l][n-1]);
        cout<<mn<<endl;
    }
    return 0;
}
