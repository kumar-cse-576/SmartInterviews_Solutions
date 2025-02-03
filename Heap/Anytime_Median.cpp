#include <bits/stdc++.h>
using namespace std;

int main() {
   int t;
   cin>>t;
   while(t--){
    priority_queue<int,vector<int>,greater<int>>mn;
    priority_queue<int> mx;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mx.push(a[0]);
    cout<<a[0]<<" ";
    for(int i=1;i<n;i++){
       if(a[i]>mx.top()){
            mn.push(a[i]);
        }else{
            mx.push(a[i]);
        }
        if(mx.size()>mn.size()+1){
            mn.push(mx.top());
            mx.pop();
        }
        if(mn.size()>mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
        cout<<mx.top()<<" ";
    }
    cout<<endl;
   }
   
   return 0;
}
