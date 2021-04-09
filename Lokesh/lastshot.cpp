#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
vector<int> adj[100005];
ll n , k , t,m;
int count1;
bool vis[100005];
void dfs(int i){
    vis[i] = true;
    count1++;
    for(int j : adj[i]){
        if(!vis[j]){
            dfs(j);
        }
    }
}

void func(){
    cin>>n>>m;
    for(int i = 0;i < m;i++){
        cin>>p>>q;
        adj[p].push_back(q);
    }
    int result = 0;
    for(int i = 1;i <= n;i++){
        count1 = 0;
        memset(vis,0,sizeof(vis));
        dfs(i);
        if(count1 > result){
            result =  count1;
        }
    }
    cout<<result<<nl;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}