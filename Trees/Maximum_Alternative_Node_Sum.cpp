#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int d;
    node*l,*r;
    node(int x){
        this->d=x;
        this->l=this->r=nullptr;
    }
};

node* insert(node* r,int x){
    if(r==nullptr)return new node(x);
    if(r->d>x)r->l=insert(r->l,x);
    else r->r=insert(r->r,x);
    return r;
}

int f(node*r,map<int,int>&mp){
    if(r==nullptr)return 0;
    if(r->d<0)return f(r->r,mp);
    if(r->l==nullptr&&r->r==nullptr)return max(r->d,0);
    if(mp.find(r->d)!=mp.end())return mp[r->d];
    int ans=f(r->l,mp)+f(r->r,mp);
    int pk=r->d;
    if(r->l!=nullptr)pk+=f(r->l->l,mp)+f(r->l->r,mp);
    if(r->r!=nullptr)pk+=f(r->r->l,mp)+f(r->r->r,mp);
    return mp[r->d]=max(pk,ans);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node*r=nullptr;
        int mx=INT_MIN;
        while(n--){
            int a;
            cin>>a;
            mx=max(mx,a);
            r=insert(r,a);
        }
        int ans=0;
        if(mx<=0){
            cout<<0<<endl;
            continue;
        }
        map<int,int> mp;
        cout<<f(r,mp)<<endl;
    }
    return 0;
}
