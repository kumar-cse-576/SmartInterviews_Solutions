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

int f(node*r,map<int,int>&dp){
    if(r==nullptr)return 0;
    if(r->d<0)return f(r->r,dp);
    if(r->l==nullptr&&r->r==nullptr)return max(r->d,0);
    if(dp.find(r->d)!=dp.end())return dp[r->d];
    int ans=f(r->l,dp)+f(r->r,dp);
    int pk=r->d;
    if(r->l!=nullptr)pk+=f(r->l->l,dp)+f(r->l->r,dp);
    if(r->r!=nullptr)pk+=f(r->r->l,dp)+f(r->r->r,dp);
    return dp[r->d]=max(pk,ans);
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
        map<int,int> dp;
        cout<<f(r,dp)<<endl;
    }
    return 0;
}
