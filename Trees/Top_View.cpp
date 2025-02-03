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

Node* insert(Node* r,int x){
    if(r==nullptr)return new Node(x);
    if(r->d>x)r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

void f(Node*r,int l,int p,map<int,pair<int,int>>&mp){
    if(r==nullptr)r;
    if(mp.find(p)==mp.end()){
        mp[p]=make_pair(r->d,l);
    }else{
        if(mp[p].second>l){
            mp[p]=make_pair(r->d,l);
        }
    }
    if(r->l!=nullptr)f(r->l,l+1,p-1,mp);
    if(r->r!=nullptr)f(r->r,l+1,p+1,mp);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   int t;
   cin>>t;
   while(t--){
    int n,a;
    cin>>n;
    Node*r=nullptr;
    while(n--){
    cin>>a;
    r=insert(r,a);
    }
    map<int,pair<int,int>> mp;
    f(r,0,0,mp); 
    for(auto it:mp){
       cout<<it.second.first<<" ";
    }
    cout<<endl;
   }
    return 0;
}
