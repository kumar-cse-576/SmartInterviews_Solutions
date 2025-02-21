#include <bits/stdc++.h>
using namespace std;


int f(vector<vector<bool>>&vi,int sx,int sy,int dx,int dy){
    if(sx==dx&&sy==dy)return 0;
    int a=vi.size()-1,b=vi[0].size()-1;
    if(dx==0||dy==0||dx>a||dy>b)return -1;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    vi[sx][sy]=true;
    int c=0;
    while(!q.empty()){
        int l=q.size();
        c++;
        while(l--){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first,y=p.second;
            int up=x+2;
           if(up<=a){
                
                if(y>1&&!vi[up][y-1]){
                    if(up==dx&&y-1==dy)return c;
                    vi[up][y-1]=true;
                    q.push(make_pair(up,y-1));
                }
                if(y<b&&!vi[up][y+1]){
                    if(up==dx&&y+1==dy)return c;
                    vi[up][y+1]=true;
                    q.push(make_pair(up,y+1));
                }
            }
            int dw=x-2;
            if(dw>0){
                if(y>1&&!vi[dw][y-1]){
                    if(dw==dx&&y-1==dy)return c;
                    vi[dw][y-1]=true;
                    q.push(make_pair(dw,y-1));
                }
                if(y<b&&!vi[dw][y+1]){
                    if(dw==dx&&y+1==dy)return c;
                    vi[dw][y+1]=true;
                    q.push(make_pair(dw,y+1));
                }
            }
            int lf=y-2;
            if(lf>0){
                if(x>1&&!vi[x-1][lf]){
                    if(x-1==dx&&lf==dy)return c;
                    vi[x-1][lf]=true;
                     q.push(make_pair(x-1,lf));
                }
                if(x<a&&!vi[x+1][lf]){
                    if(x+1==dx&&lf==dy)return c;
                    vi[x+1][lf]=true;
                     q.push(make_pair(x+1,lf));
                }
            }
             int rt=y+2;
            if(rt<=b){
                if(x>1&&!vi[x-1][rt]){
                    if(x-1==dx&&rt==dy)return c;
                    vi[x-1][rt]=true;
                     q.push(make_pair(x-1,rt));
                }
                if(x<a&&!vi[x+1][rt]){
                    if(x+1==dx&&rt==dy)return c;
                    vi[x+1][rt]=true;
                     q.push(make_pair(x+1,rt));
                }
            }
            
        }
    }
    return -1;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--){
        int a,b,sx,sy,dx,dy;
        cin>>a>>b>>sx>>sy>>dx>>dy;
        vector<vector<bool>> vi(a+1,vector<bool>(b+1,false));
        int c=f(vi,sx,sy,dx,dy);
        cout<<c<<endl;
    }
    
    return 0;
}
