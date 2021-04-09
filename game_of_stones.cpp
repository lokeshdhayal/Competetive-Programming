#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

bool a[101];

void sieve(){
    a[2] = true;
    a[3] = true;
    a[5] = true;
    for(int i = 6;i <= 100;i++){
        if(!a[i - 2]){
            a[i] = true;
        }
        if(!a[i - 3]){
            a[i] = true;
        }
        if(!a[i - 5]){
            a[i] = true;
        }
    }
}


void func(){
    cin>>n;
    if(a[n]){
        cout<<"First"<<nl;
    }
    else{
        cout<<"Second"<<nl;
    }
}

int main(){
    sieve();
    cin>>t;
    while(t--){
        func();
    }
} 