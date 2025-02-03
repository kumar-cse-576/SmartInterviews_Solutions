#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int tn=n;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(n--){
            int a;
            cin>>a;
            pq.push(a);
        }
        int la;
        while(k>0){
            la=pq.top();
            pq.pop();
            k--;
        }
        cout<<la<<endl;
    }
    return 0;
}
