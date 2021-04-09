#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2 ,p , q ,  r , root;

map<ll , ll> hashmap;

ll solve(vi a , vi b , ll k){
    if(hashmap.find(k) != hashmap.end()){
        return hashmap[k];
    }
    if(k < a.size()){
        return hashmap[k] = a[k];
    }
    ll res = 0;
    for(ll i = 0;i < b.size();i++){
        res = (res + solve(a , b , k - 1 - i)*b[i])%mod;
    }
    return hashmap[k] = res;
}

void func(){
    hashmap.clear();
    cin>>n;
    vi a;
    vi b;
    ll k;
    for(ll i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(ll i = 0;i < n;i++){
        cin>>temp;
        b.push_back(temp);
    }
    cin>>k;
    cout<<solve(a , b , k - 1)<<'\n';

}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 