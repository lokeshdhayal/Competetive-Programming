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
    cin>>m>>n>>k;
    if(m + n == k){
        cout<<"YES"<<nl;
        return;
    }
    if(m + k == n){
        cout<<"YES"<<nl;
        return;
    }
    if(n + k == m){
        cout<<"YES"<<nl;
        return;
    }
    cout<<"NO"<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}