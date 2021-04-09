#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define pd push_back
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root , k;
int ct , cc;

void dfs(int i , int t , int c ,vector<vi> & time , vector<vi> & cost , vb & vis){
    if(i == n - 1){
        if(c < cc){
            cc = c;
            ct = t;
        }
        return;
    }
    for(int j = 0;j < n;j++){
        if(vis[j]){
            continue;
        }
        if(t + time[i][j] <= k && c + cost[i][j] <= cc){
            vis[j] = true;
            dfs(j , t + time[i][j] , c + cost[i][j] , time , cost , vis);
            vis[j] = false;
        }
    }
}

void func(){
    vector<vi> time(n , vi(n));
    vector<vi> cost(n , vi(n));
    vb vis(n , false);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>time[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cin>>cost[i][j];
        }
    }
    if(time[0][n - 1] <= k){
        ct = time[0][n - 1];
        cc = cost[0][n - 1];
    }
    else{
        ct = k;
        cc = INF;
    }
    vis[0] = true;
    dfs(0 , 0 , 0 , time , cost , vis);
    cout<<cc<<" "<<ct<<'\n';
    cin>>n>>k;
}



int main(){
    cin>>n>>k;
    while(n != 0 && k != 0){
        func();
    }
} 