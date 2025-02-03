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

void f(Node*r,map<int,vector<int>>&mp,int l,int p){
    if(r==nullptr)return;
    mp[p].push_back(r->d);
    if(r->l!=nullptr)f(r->l,mp,l+1,p-1);
    if(r->r!=nullptr)f(r->r,mp,l+1,p+1);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        map<int,vector<int>> mp;
        Node*r=nullptr;
        while(n--){
            cin>>a;
            r=insert(r,a);
        }
        f(r,mp,0,0);
        for(auto it:mp){
            vector<int> rr=it.second;
            sort(rr.begin(),rr.end());
            for(auto i:rr){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
