#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* c[2];
    Node(){
        c[0]=nullptr;
        c[1]=nullptr;
    }
};

void insert(Node*r,int msb,int x){
    int ans=0;
    for(int i=msb;i>=0;i--){
        int bv=(x&(1<<i))?1:0;
        if(r->c[bv]==nullptr){
            r->c[bv]=new Node();
        }
        r=r->c[bv];
    }
}

int fnd(Node*r,int msb,int x){
    int ans=0;
    for(int i=msb;i>=0;i--){
        int bv=(x&(1<<i))?1:0;
        if(r->c[1-bv]==nullptr){
            r=r->c[bv];
        }else{
            ans|=(1<<i);
            r=r->c[1-bv];
        }
    }
    return ans;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        int mxb=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            int v=a[i]+1;
            int mb=ceil(log2(a[i]));
            if(mb>mxb){
                mxb=mb;
            }
        }
        Node*r=new Node();
        for(int i=0;i<n;i++){
        insert(r,mxb,a[i]);
        }
        int xr=0;
        for(int i=0;i<n;i++){
            xr=max(xr,fnd(r,mxb,a[i]));
        }
        cout<<xr<<endl;
    }
    return 0;
}
