#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,w1,w2,W,m,papu = 0,k,d,temp;
void func(){
    cin>>n>>k>>d;
    ll sum = 0;
    for(ll i = 0;i < n;i++)cin>>temp,sum += temp;
    if(int(sum/k) < d)cout<<(sum / k)<<nl;else cout<<d<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
