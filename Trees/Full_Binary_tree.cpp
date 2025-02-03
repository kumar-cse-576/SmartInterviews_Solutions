#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int d;
    Node*l,*r;
    Node(int x){
        this->d=x;
        this->l=this->r=nullptr;
    }
};

Node* insert(Node* r,int x){
    if(r==nullptr)return new Node(x);
    if(r->d>x){
        r->l=insert(r->l,x);
    }else{
        r->r=insert(r->r,x);
    }
    return r;
}


bool fbt(Node*r){
    if(r==nullptr||(r->l==nullptr&&r->r==nullptr))return true;
    if(r->l==nullptr||r->r==nullptr)return false;
    return fbt(r->l)&&fbt(r->r);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int t;
   cin>>t;
   while(t--){
    int n,mxl=0;
    cin>>n;
    Node*r=nullptr;
    while(n--){
        int a;
        cin>>a;
        r=insert(r,a);
    }
    if(fbt(r)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
   }
    return 0;
}
