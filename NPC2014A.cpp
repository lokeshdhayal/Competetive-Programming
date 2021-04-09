#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

ll count_prime(ll num){
    ll count1 = 0;
    for(int i = 2;i <= num;i++){
        while(num%i == 0){
            count1++;
            num /= i;
        }
    }
    return count1;
}

void func(){
    cin>>n;
    ll res = 0;
    vector<ll> a(n , 0);
    for(ll i = 0;i < n;i++){
        cin>>temp;
        res ^= count_prime(temp);
    }
    if(n == 0){
        cout<<"Joke is the bestest player in teh wurld"<<nl;
        return;
    }
    if(res > 0){
        cout<<"Puguh is the bestest player in teh wurld"<<nl;
    }
    else{
        cout<<"Joke is the bestest player in teh wurld"<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 
