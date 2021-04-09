#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k , res;
string s;
map<pair<vector<bool> , ll >, ll> hashmap;

ll find_v(vector<int>  adj[] , vector<bool> & vis , int i){
    if(i == n){
        return 1;
    }
    if(hashmap.find({vis , i}) != hashmap.end()){
        return hashmap[{vis , i}];
    }
    ll res = 0;
    for(int j : adj[i]){
        if(vis[j] == false){
            vis[j] = true;
            res += find_v(adj , vis , i + 1);
            vis[j] = false;
        }
    }
    return res;
}


void func(){
    hashmap.clear();
    cin>>n;
    vector<int> adj[n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>temp;
            if(temp == 1){
                adj[i].push_back(j);
            }
        }
    }
    ll res = 0;
    vector<bool> vis(n , false);
    for(int i : adj[0]){
        vis[i] = true;
        res += find_v(adj , vis , 1);
        vis[i] = false;
    }
    cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 