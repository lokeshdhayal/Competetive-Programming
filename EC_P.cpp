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
int in[10000];
int lok;
int out[10000];
priority_queue<pair<int , int> , vector<pair<int , int> > , greater<pair<int,int> >> pq;
int timer = 0;
void dfs(int i , int p , vector<bool> & vis , vector<int> adj[]){
    vis[i] = true;
    in[i] = out[i] = timer++;
    for(int j : adj[i]){
        if(j == p)continue;
        if(vis[j]){
            out[i] = min(out[i] , out[j]);
        }
        else{
            dfs(j,i,vis,adj);
            out[i] = min(out[j] , out[i]);
            if(out[j] > in[i]){
                if(i > j)
                    pq.push({j , i});
                else{
                    pq.push({i , j});
                }
            }
        }
    }
}
void func(){
    cin>>n>>m;
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
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i , -1 , vis , adj);
        }
    }
    cout<<"Caso #"<<(lok - t)<<nl;
    if(pq.empty()){
        cout<<"Sin bloqueos"<<nl;
        return;
    }
    cout<<pq.size()<<nl;
    while(!pq.empty()){
        cout<<pq.top().first<<" "<<pq.top().second<<nl;
        pq.pop();
    }
}


int main(){
    cin>>t;
    lok = t;
    while(t--){
        func();
    }
}
