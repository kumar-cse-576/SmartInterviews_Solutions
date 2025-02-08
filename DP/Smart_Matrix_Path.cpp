#include <bits/stdc++.h>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int t;
   cin>>t;
   while(t--){
  
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
   vector<vector<int>> dp(n,vector<int>(m,0));
   int mn=INT_MIN;
   for(int i=0;i<n;i++){
    dp[i][0]=a[i][0];
   }
   for(int i=1;i<m;i++){
    for(int j=0;j<n;j++){
        int up=0,lt=0,dw=0;
        if(j>0){
            up=dp[j-1][i-1];
        }else{
            up=dp[n-1][i-1];
        }
        lt=dp[j][i-1];
        if(j<n-1){
            dw=dp[j+1][i-1]; 
        }else{
            dw=dp[0][i-1];
        }
       
        dp[j][i]=max(up,max(lt,dw))+a[j][i];
    }
   }
   for(int i=0;i<n;i++){
    mn=max(mn,dp[i][m-1]);
   }
   cout<<mn<<endl;
   

   }
    return 0;
}
