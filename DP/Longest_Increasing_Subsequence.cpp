#include <bits/stdc++.h>
using namespace std;

int bs(vector<int>&a,int l,int h,int k){
    int res=INT_MAX;
    while(l<=h){
        int m=(l+h)/2;
        if(a[m]<k)l=m+1;
        else{
            res=min(res,m);
            h=m-1;
        }
    }
    return res;
}


int main() {
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    int ci=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b[ci++]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]==b[ci-1])continue;
        if(a[i]>b[ci-1]){
            b[ci++]=a[i];
        }else if(b[0]>a[i]){
            b[0]=a[i];
        }else{
            int nci=bs(b,0,ci-1,a[i]);
            if(nci!=INT_MAX)
            b[nci]=a[i];
        }
    }
    cout<<ci<<endl;
}        
    
return 0;
}
