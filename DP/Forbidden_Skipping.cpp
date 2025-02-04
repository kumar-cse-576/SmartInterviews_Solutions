#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
       for(int i=0;i<n;i++)cin>>a[i];
        long long int l0=a[0],l1=0;
        for(int i=1;i<n;i++){
            long long int cl0,cl1;
            cl0=a[i]+max(l0,l1);
            cl1=l0;
            l0=cl0,l1=cl1;
        }
        cout<<max(l0,l1)<<endl;
    }
    return 0;
}
