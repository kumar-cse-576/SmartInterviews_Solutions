#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        priority_queue<int,vector<int>,greater<int>> mn;
        
        for(int i=0;i<n;i++){
            cin>>a[i];
            mn.push(a[i]);
        }
        int c=0;
        while(mn.size()>1){
            int a=mn.top();mn.pop();
            int b=mn.top();mn.pop();
            c+=a+b;
            mn.push(a+b);
        }
        cout<<c<<endl;
        
    }
    return 0;
}
