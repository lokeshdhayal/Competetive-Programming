#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

//double long fac[1000001];

ll p,q;

long long C(ll n , ll k){
    if(k > n - k){
        k = n - k;
    }
    ll res = 1;
    for(int i = 1;i <= k;i++){
        res = res * (n - i + 1) / i;
    }
   // cout<<res<<nl;
    return res;
}

void func(){
    ll n , k;
    cin>>n>>k;
    cout<<C(n - 1,k - 1)<<nl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        func();
    }
}