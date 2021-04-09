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

bool comp(vi a , vi b){
    if(a[0] < b[0]){
        return true;
    }
    return false;
}

void func(){
    ll k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0;i < n*k;i++){
        cin>>a[i];
    }
    ll res = 0;
    while(k > 0){
        
    }
    cout<<res<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 