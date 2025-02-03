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

void f(Node*r,int d,int l,map<int,vector<pair<int,int>>>&mp){
if(r==nullptr)return;
mp[d].push_back(make_pair(r->d,l));
if(r->l!=nullptr)f(r->l,d,l+1,mp);
if(r->r!=nullptr)f(r->r,d+1,l+1,mp);
}

static bool comp(pair<int,int>&p1,pair<int,int>&p2){
    if(p1.first>p2.first)return true;
    return false;
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
        map<int,vector<pair<int,int>>> mp;
        f(r,0,0,mp);
        for(auto it:mp){
            sort(it.second.begin(),it.second.end(),comp);
            for(auto i:it.second)cout<<i.first<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
