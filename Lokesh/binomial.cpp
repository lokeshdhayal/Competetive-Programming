#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;

ll a,b,c,d,sum;

ll binpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b & 1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b >>= 1;
    }
    return res;
}

ll C(ll n,ll k){
    ll res = 1;
    for(ll i = n - k + 1;i <= n;i++){
        res = (res*i)%mod;
    }
    for(ll i = 2; i <= k;i++){
        res = (res * binpow(i,mod-2)) % mod;
    }
    return res;
}

void func(){
    ll x,y;
    cin>>x>>y>>n>>k;
    ll comb = C(n,k);
    cout<<comb<<nl;
    ll res = (binpow(x,k) * binpow(y , n - k))%mod;
    cout<<binpow(y,n - k)<<nl;
    res = (res * comb)%mod;
    cout<<res;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}
