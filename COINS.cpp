#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;

map<ll , ll > hashmap;

ll find_v(ll n){
    if(hashmap[n] > 0){
        return hashmap[n];
    }
    if(n == 0){
        return 0;
    }
    return hashmap[n] = max(n , find_v(n / 2) + find_v(n / 3) + find_v(n / 4));
}

int main(){
  //  sieve();
    while(cin>>n){
        cout<<find_v(n)<<nl;
    }
} 