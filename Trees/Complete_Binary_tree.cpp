#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int d;
    Node *l,*r;
    Node(int x){
        this->d=x;
       this->r=this->l=nullptr;
    }
};

Node* insert(Node*r,int x){
    if(r==nullptr)return new Node(x);
    if(r->d>x)r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

bool cbt(Node*r){
    if(r==nullptr)return true;
    queue<Node*> q;
    q.push(r);
    bool f=true;
    while(!q.empty()){
        int l=q.size();
        while(l--){
            Node*p=q.front();
            q.pop();
            if(!f&&(p->l!=nullptr||p->r!=nullptr))return false;
            if(p->l==nullptr&&p->r!=nullptr)return false;
            if(p->l==nullptr||p->r==nullptr)f=false;
            if(p->l!=nullptr)q.push(p->l);
            if(p->r!=nullptr)q.push(p->r);
        }
    }
    return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node*r=nullptr;
        while(n--){
            int a;
            cin>>a;
            r=insert(r,a);
        }
        if(cbt(r)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
