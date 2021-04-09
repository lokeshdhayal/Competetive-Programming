#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

bool a[100005];
vector<bool> b(100005 , false);
void sieve(){
    for(ll i = 2;i <= 100000;i++){
        if(!a[i]){
            b[i] = !b[i - 1];
        }
        else{
            b[i] = b[i  - 1];
        }
        if(!a[i]){
            for(ll j = i * i ; j <= 100000;j += i){
                a[j] = true;
            }
        }
    }
}

void func(){
    cin>>n;
    if(b[n]){
        cout<<"Alice"<<nl;
    }
    else{
        cout<<"Bob"<<nl;
    }
}

int main(){
    sieve();
    cin>>t;
    while(t--){
        func();
    }
} 
