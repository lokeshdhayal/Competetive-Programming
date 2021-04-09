#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q , r , x = 0;
ll n , k , t,m;

void func(){
    cin>>n>>k;
    vector<ll> a(n , 0);
    for(ll i = 0;i < k;i++){
        cin>>p>>q>>r;
        a[p] += r;
        if(q + 1 <= n){
            a[q + 1] -= r;
        }
    }
    ll res =  0;
    for(ll i = 0;i <= n;i++){
        x += a[i];
        if(res < x){
            res = x;
        }
    }
    cout<<res<<nl;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}

