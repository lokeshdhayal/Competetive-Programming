#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;
vector<bool> res(1000005 , false);

void sieve(){
    int p = 1;
    for(int i = 1;i <= 1000000;i++){
        for(int j = 1;((i - j*j) >= 0);j++){
            res[i] = res[i] | !res[i - j*j];
            if(res[i]){
                break;
            }
        }
       // cout<<i<<" ";
    }
}

void func(){
    cin>>n;
    if(res[n]){
        cout<<"Win"<<nl;
    }
    else{
        cout<<"Lose"<<nl;
    }
}

int main(){
    sieve();
    cin>>t;
    while(t--){
        func();
    }
} 