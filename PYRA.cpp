#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://o...content-available-to-author-only...s.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;


ll dfs(vector<bool> & vis , vi adj[], int par , int i , vector<ll> & value){
    vis[i] = true;
    ll j = 0;
    ll res = 0;
    for(int k : adj[i]){
        if(k == par){
            continue;
        }
        else if(vis[k] == false){
            j++;
            res += dfs(vis , adj , i , k , value);
        }
    }
    res += (j + 1);
    return value[i] = res;
}


void func(){
    cin>>n;
    vi adj[n];
    vi value(n);
    for(int i = 0;i < n - 1;i++){
        cin>>p>>q;
        adj[p].push_back(q);
        adj[q].push_back(p);    
    }
    ll res = 0;
    p = 0;
    vector<bool> vis(n , false);
    vis[0] = true;
    for(int i : adj[0]){
        p++;
        res += dfs(vis , adj , 0 , i , value);
    }
    res += (p + 1);
    value[0] = res;
    res = 0;
    for(int i = 0;i < value.size();i++){
     //   cout<<value[i]<<" ";
        res += value[i];
    }
    cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        k++;
        func();
    }
} 