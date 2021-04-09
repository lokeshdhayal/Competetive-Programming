#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 , p , q , r , root;


void func(){
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    ll res = 0;
    p = 0;
    for(int i = n - 1;i >= 1;i--){
        p += a[i];
        res += abs(p);
    }
    cout<<res<<nl;
    cin>>n;
}

int main(){
    cin>>n;
    while(n != 0){
        func();
    }
} 