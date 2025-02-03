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

Node* insert(Node *r,int x){
    if(r==nullptr)return new Node(x);
    if(x<r->d)r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}



int dim(Node*r ,int &mx){
    if(r==nullptr)return 0;
    if(r->l==nullptr&&r->r==nullptr)return 1;
    int lf=0,rf=0;
    if(r->l!=nullptr){
        lf=dim(r->l,mx);
    }
    if(r->r!=nullptr){
        rf=dim(r->r,mx);
    }
    mx=max(mx,lf+rf+1);
    return max(lf,rf)+1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *r=nullptr;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            r=insert(r,a);
        }
        int mx=0;
        dim(r,mx);
        cout<<mx<<endl;
    }           
    return 0;
}
