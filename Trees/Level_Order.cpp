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

int main() {
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
        queue<Node*>q;
        q.push(r);
        while(!q.empty()){
            int l=q.size();
            while(l--){
                Node*p=q.front();
                q.pop();
                cout<<p->d<<" ";
                if(p->l!=nullptr)q.push(p->l);
                if(p->r!=nullptr)q.push(p->r);
            }
            cout<<endl;
        }
        cout<<endl;

    }

    return 0;
}
