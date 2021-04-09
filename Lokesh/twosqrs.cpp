#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;

void func(){
    ll n;
    cin>>n;
    for(ll i = 0;i*i <= n;i++){
        double lok  = sqrt(n - i*i);
        if((lok - floor(lok)) == 0){
         //   cout<<i<<" "<<lok<<nl;
            cout<<"Yes"<<nl;
            return;
        }
    }
    cout<<"No"<<nl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        func();
    }
}