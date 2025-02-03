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
Node* insert(Node*r,int x){
    if(r==nullptr)return new Node(x);
    if(r->d>x)r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

Node* lca(Node *r,int a,int b){
if(r==nullptr)return nullptr;
if(r->d==a||r->d==b)return r;
if(r->d<min(a,b))return lca(r->r,a,b);
if(r->d>max(a,b))return lca(r->l,a,b);
return r;
/*
if(r->l==nullptr&&r->r==nullptr)return nullptr;
Node *lf,*rf;
lf=lca(r->l,a,b);
rf=lca(r->r,a,b);
if(lf!=nullptr&&rf!=nullptr)return r;
if(lf==nullptr)return rf;
else return lf;
*/

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int t;
  cin>>t;
  while(t--){
    int n,q;
    cin>>n>>q;
    Node *r=nullptr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        r=insert(r,a);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        Node *p=lca(r,a,b);
        if(p!=nullptr)cout<<p->d<<" ";
    }
    cout<<endl;
  }
    return 0;
}
