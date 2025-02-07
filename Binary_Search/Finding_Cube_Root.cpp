#include <bits/stdc++.h>
using namespace std;

int cr(long long int l,long long int h,long long int a)
{
    if(l<=h){
        long long int m=(l+h)/2;
        long long int t=a;
        t=t/m;
        t=t/m;
        if(t==m)return m;
        if(t<m)return cr(l,m-1,a);
        else return cr(m+1,h,a);
    }
    return 0;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        long long int a;
        bool neg=false;
        cin>>a;
        if(a==0)cout<<0<<endl;
        else{
            if(a<0)neg=true;
            a=abs(a);
            long long int ans=cr(1,a,a);
            ans*=(neg)?-1:1;
            cout<<ans<<endl;
        }
    }
    return 0;
}
