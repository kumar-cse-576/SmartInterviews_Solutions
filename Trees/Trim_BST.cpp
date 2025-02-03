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

Node* trim(Node*r ,int l,int h){
    if(r==nullptr)return r;
    if(r->d<l)return trim(r->r,l,h);
    else if(r->d>h)return trim(r->l,l,h);
    else{
        r->l=trim(r->l,l,h);
        r->r=trim(r->r,l,h);
    }
    return r;
}


void preOrd(Node*r){
    if(r==nullptr)return;
    cout<<r->d<<" ";
    preOrd(r->l);
    preOrd(r->r);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,l,h;
        cin>>n>>l>>h;
        Node*r=nullptr;
        while(n--){
            int a;
            cin>>a;
            r=insert(r,a);
        }
        r=trim(r,l,h);
        preOrd(r);
        cout<<endl;
    }
    return 0;
}
