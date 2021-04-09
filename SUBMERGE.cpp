#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,i,j,w1,w2,W,m,papu = 0,k,d,temp,x,y,p ,q;
int a[1001];
ll res;
int in[10005];
int lok;
int out[10005];
int timer = 0;
void dfs(int i , int p , vector<bool> & vis , vector<int> adj[]){
    vis[i] = true;
    in[i] = out[i] = timer++;
    int children = 0;
    for(int j : adj[i]){
        if(j == p)continue;
        if(vis[j]){
            out[i] = min(out[i] , out[j]);
        }
        else{
            dfs(j,i,vis,adj);
            out[i] = min(out[j] , out[i]);
            if(out[j] >= in[i] && p != -1){
                res++;
            }
            ++children;
        }
    }
    if(p == -1 && children > 1){
        res++;
    }
}
void func(){
    vector<int> adj[n + 1];
    for(int i = 0;i < m;i++){
        cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }
    timer = 0;
    memset(in , 0 , sizeof(in));
    memset(out , 0 , sizeof(out));
    vector<bool> vis(n + 1 , false);
    res = 0;
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i , -1 , vis , adj);
        }
    }
    cout<<res<<nl;
    cin>>n>>m;
}


int main(){
    cin>>n>>m;
    while(m != 0 && n != 0){
        func();
    }
}
