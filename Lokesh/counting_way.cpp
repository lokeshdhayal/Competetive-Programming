#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;

ll a[1000];
ll F[505];

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

void sieve(){
    F[0] = 1;
    F[1] = 1;
    for(int i = 2;i <= 500;i++){
        F[i] = (i * F[i - 1]) % mod;
    }
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
    cin>>n>>k;
    vector<int> lok(n + 1 , 0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j <= k;j++){
            if(i + j <= n){
                lok[i + j]++;
            }
        }
    }
    cout<<lok[n]<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
