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

Node* insert(Node*r,int d){
    if(r==nullptr){
        return new Node(d);
    }else{
        if(r->d<d){
            r->r=insert(r->r,d);
        }else{
            r->l=insert(r->l,d);
        }
    }
    return r;
}
int height(Node*r){
    if(r==nullptr)return -1;
    return 1+max(height(r->l),height(r->r));
}
 
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node* r=nullptr;
        while(n--){
            int a;
            cin>>a;
            r=insert(r,a);
        }
        cout<<height(r)<<endl;
    }
    return 0;
}
