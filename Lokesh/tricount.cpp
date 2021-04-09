#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,x,t,m,k,count1,result;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}


void func(){
    cin>>n;
    ll result = n * (n + 2) * (2 * n + 1) / 8;
    cout<<result<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}