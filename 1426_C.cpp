#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;

ll min_v(ll a , ll b){
    if(a < b){
        return a;
    }
    return b;
}

void func(){
    cin>>n;
    if(n == 1){
        cout<<0<<nl;
        return;
    }
    double p = (double)(sqrt(n));
    if(p == (int)p){
        cout<<(2*p - 2)<<nl;
        return;
    }
    q = ceil(sqrt(n));
    cout<<(q - 2 + ceil(((double)n / q)))<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 