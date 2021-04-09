#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll n , t , m , temp , temp2 , p , q , r , root;

void func(){
    priority_queue< pair<int, int> , vector<pair<int , int> > , greater<pair<int , int> > >pq;
    cin>>n;
    vector<int> dis(n + 1 , mod);
    vector<pair<int , int> > adj[n + 1];
    for(int i = 0;i < n;i++){
        cin>>p>>q>>r;
        adj[p].push_back({r , q});
        adj[q].push_back({r , p});
    }
    cin>>root;
    dis[root] = 0;
    pq.push({0, root});
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        for(pair<int , int> i : adj[curr]){
            if(curr_d + i.first < dis[i.second]){
                dis[i.second] = curr_d + i.first;
                pq.push({ dis[i.second] , i.second});
            }
        }
    }
    for(int i = 0;i <= n;i++){
        cout<<dis[i]<<" ";
    }
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>p;
        if(dis[p] != mod){
            cout<<dis[p]<<nl;
        }
        else{
            cout<<"NO PATH"<<nl;
        }
    }
}

int main(){
    t = 1;
    while(t--){
        func();
    }
} 