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
    else{
        if(r->d<x){
            r->r=insert(r->r,x);
        }else{
            r->l=insert(r->l,x);
        }
    }
    return r;
}

int minR(Node*r){
    if(r==nullptr)return INT_MAX;
    return min(r->d,minR(r->l));
}

Node* delN(Node*r,int x){
    if(r==nullptr)return r;
    if(r->d>x){
        r->l=delN(r->l,x);
    }else if(r->d<x){
        r->r=delN(r->r,x);
    }else{
        if(r->l==nullptr&&r->r==nullptr)return nullptr;
        else if(r->l==nullptr)return r->r;
        else if(r->r==nullptr)return r->l;
        else{
            int v=minR(r->r);
            r->r=delN(r->r,v);
            r->d=v;
        }
    }
    return r;
}

bool find(Node*r,int x){
    if(r==nullptr)return false;
    else{
        if(r->d==x)return true;
        else if(r->d>x)return find(r->l,x);
        else return find(r->r,x);
    }
}

void preOrd(Node*r){
    if(r==nullptr)return;
    cout<<r->d<<" ";
    preOrd(r->l);
    preOrd(r->r);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,i=1;
    cin>>t;
    while(t--){
        cout<<"Case #"<<i++<<":"<<endl;
        int q;
        cin>>q;
        Node *r=nullptr;
        while(q--){
            int a,x;
            cin>>a;
            if(a!=4){cin>>x;}
            if(a==1){
                r=insert(r,x);
            }else if(a==2){
                r=delN(r,x);
            }else if(a==3){
                if(find(r,x)){
                    cout<<"Yes"<<endl;
                }else{
                    cout<<"No"<<endl;
                }
            }else{
                preOrd(r);
                cout<<endl;
            }

        }
    }
    return 0;
}
