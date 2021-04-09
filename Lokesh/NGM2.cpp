#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}


void func(){
    cin>>n>>k;
    p = (1 << k);
    vector<ll> a(n);
    for(ll i = 0;i < k;i++){
        cin>>a[i];
    }
    ll res = n;
    for(ll i = 1;i < p;i++){
        ll bit_count = 0;
        ll demon = 1L;
        for(ll j = 0;j < k;j++){
            if(i & (1 << j)){
                bit_count++;
                demon = demon / gcd(a[j] , demon) * a[j];
            }
        }
        if(bit_count & 1){
            res -= (n / demon);
        }
        else{
            res += (n / demon);
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
