#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;


void func(){
    cin>>n;
    if(n%2 == 1){
        cout<<"Sorry Shaktiman"<<nl;
    }
    else{
        cout<<"Thankyou Shaktiman"<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 