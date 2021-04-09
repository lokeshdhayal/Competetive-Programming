#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;


void func(){
    cin>>n;
    int a[n];
    ll maxi = 0;
    map<ll , ll> hashmap;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        hashmap[a[i]]++;
        maxi = max(hashmap[a[i]] , maxi);
    }
    vi v;
    for(auto i : hashmap){
        v.push_back(i.second);
    }
    sort(v.begin() , v.end());
    ll res = n - hashmap.size();

    for(ll i = 1;i < maxi + 1;i++){
        ll idx = lower_bound(v.begin() , v.end() , i) - v.begin();
        ll x = (v.size() - idx)*i;
      //  cout<<i<<" "<<idx<<'\n';
        res = min(res ,n - x);
    }
    cout<<res<<'\n';

}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 