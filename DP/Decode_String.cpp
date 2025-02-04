#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<long long int> r(s.size()+1,0);
        r[n]=1;
        for(int i=n-1;i>=0;i--){
            if(i==n-1)r[i]=r[i+1];
            else{
                r[i]=r[i+1];
                if(s[i]=='1'||(s[i]=='2'&&s[i+1]<'6')){
                    r[i]=(r[i]%mod+r[i+2]%mod)%mod;
                }
            }
        }
        cout<<r[0]<<endl;
    }
    return 0;
}
