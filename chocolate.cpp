#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp;



void func(){
    cin>>n;
    ll res = 0;
    vector<ll> a;
    for(int i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp);
        res ^= temp;
    }
    int p = 0;
    for(int i = 0;i < n;i++){
        if(res^a[i] < a[i]){
            p++;
        }
    }
    cout<<p<<nl;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}