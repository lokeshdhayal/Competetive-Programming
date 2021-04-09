#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2 , p , q , r , root;

int par[10005];

bool comp(vector<int> a , vector<int> b){
    if(a[2] < b[2]){
        return true;
    }
    return false;
}

int find_v(int i){
    if(par[i] == -1){
        return i;
    }
    return par[i] = find_v(par[i]);
}

void union_v(int i , int j){
    par[find_v(j)] = i;
}


void func(){
    cin>>n;
    string s;
    memset(par , -1 , sizeof(par));
    vector<vector<int> >  adj;
    for(int i = 1;i <= n;i++){
        cin>>s;
        vector<int> a(3);
        cin>>q;
        while(q--){
            a[0] = i;
            cin>>a[1]>>a[2];
            adj.push_back(a);
        }
    }
    ll res = 0;
    sort(adj.begin() , adj.end() , comp);
    /*for(int i = 0;i < adj.size();i++){
        for(int j = 0;j < 3;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<nl;
    }*/
    for(int i = 0;i < adj.size();i++){
        int p = find_v(adj[i][0]);
        int q = find_v(adj[i][1]);
        if(p != q){
       //     cout<<p<<" "<<q<<" "<<adj[i][0]<<" "<<adj[i][1]<<" ";
            res += adj[i][2];
            union_v(adj[i][1] , adj[i][0]);
     //       cout<<find_v(adj[i][0])<<" "<<find_v(adj[i][1])<<nl;
        }
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 