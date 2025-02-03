#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int d;
    Node *l,*r;
    Node(int x){
        this->d=x;
        this->l=this->r=nullptr;
    }
};

Node* insert(Node*r,int x,int &dpt){
    if(r==nullptr)return new Node(x);
    dpt++;
    if(r->d>x)r->l=insert(r->l,x,dpt);
    else r->r=insert(r->r,x,dpt);
    return r;
}

int main() {
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    Node *r=nullptr;
    map<int,int>mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        int dpt=0;
        r=insert(r,a[i],dpt);
        cout<<dpt<<" ";
    }
    cout<<endl;
   }
   return 0;
}
