#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define pd push_back
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}

void func(){
    cin>>n;
    ll res;
    res = binpow(10 , n) % mod;
    res = (res - binpow(9 , n))% mod;
    res = (res - binpow(9 , n)) % mod;
    res = (res + binpow(8 , n))% mod;
    res = (res + mod)%mod;
    cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 