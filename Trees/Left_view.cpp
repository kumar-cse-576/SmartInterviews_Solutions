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

Node* insert(Node*r,int x){
    if(r==nullptr)return new Node(x);
    if(r->d>x)r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
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
        queue<Node*> q;
        q.push(r);
        vector<int> res;
        while(!q.empty()){
            int f=1;
            int l=q.size();
            while(l--){
                Node* p=q.front();
                if(f){
                    res.push_back(p->d);
                    f=0;
                }
                q.pop();
                if(p->l!=nullptr)q.push(p->l);
                if(p->r!=nullptr)q.push(p->r);
            }
        }
        for(auto it:res)cout<<it<<" ";
        cout<<endl;

    }
    return 0;
}
