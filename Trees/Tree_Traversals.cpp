#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int d;
    Node *l,*r;
    Node(int d){
        this->d=d;
        this->l=nullptr;
        this->r=nullptr;
    }
};

Node* insert(Node*r,int x){
    if(r==nullptr)return new Node(x);
    if(r->d>x){
        r->l=insert(r->l,x);
    }else{
        r->r=insert(r->r,x);
    }
    return r;
}

void preOrd(Node*r){
    if(r==nullptr)return;
    cout<<r->d<<" ";
    preOrd(r->l);
    preOrd(r->r);
}
void inOrd(Node*r){
    if(r==nullptr)return;
    inOrd(r->l);
    cout<<r->d<<" ";
    inOrd(r->r);
}
void postOrd(Node*r){
    if(r==nullptr)return;
    postOrd(r->l);
    postOrd(r->r);
    cout<<r->d<<" ";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        Node*r=nullptr;
        cin>>n;
        while(n--){
            int a;
            cin>>a;
            r=insert(r,a);
        }
        preOrd(r);cout<<endl;
        inOrd(r);cout<<endl;
        postOrd(r);cout<<endl;
    }
    return 0;
}
