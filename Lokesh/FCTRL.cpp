#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;


void func(){
    cin>>n;
    ll res = 0;
    ll p = 5;
    while(p <= n){
        res += (n / p);
        p *= 5;
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
