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
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            r=insert(r,a);
        }
        queue<Node*> q;
        //cout<<r->d<<endl;
        q.push(r);
        vector<int>res;
        while(!q.empty()){
            int l=q.size();
            //cout<<"out l::"<<l<<endl;
            while(l--){
                //cout<<l<<" ";
                Node* p=q.front();
                q.pop();
                if(p->l!=nullptr)q.push(p->l);
                if(p->r!=nullptr)q.push(p->r);
                if(l==0){
                    //cout<<p->d<<" << ";
                    res.push_back(p->d);
                }
            }
        }
        //cout<<"size ::"<<res.size();
        for(int i=0;i<res.size();i++)cout<<res[i]<<" ";
        cout<<endl;

    }
    
    return 0;
}
