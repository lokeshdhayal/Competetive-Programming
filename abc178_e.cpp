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
    cin>>n;
    vector<pair<ll , ll > > a;
    for(int i = 0 ;i < n;i++){
        cin>>p>>q;
        a.push_back({p , q});
    }
    ll res = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            res = max(res , abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second));
        }
    }
    cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 