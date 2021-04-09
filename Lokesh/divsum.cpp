#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
ll n , k , t,m;
ll a[500005];
void sieve(){
    for(ll i = 1;i <= 500000;i++){
        for(ll j = i * 2;j <= 500000;j += i){
            a[j] += i;
        }
    }
}
void func(){
    cin>>n;
    cout<<a[n]<<nl;
}

int main(){
    cin>>t;
    sieve();
    //cout<<"YES";
    while(t--){
        func();
    }
}

