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
ll n , t , m , temp , temp2 ,p , q ,  r , root , k;

bool check(ll mid , vi v){
    ll p = mid + v[0];
    for(int i = 1;i < v.size();i++){
        if((double)v[i] / p > (double)k / 100){
            return false;
        }
        p += v[i];
    }
    return true;
}

void func(){
    cin>>n>>k;
    vi v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    ll l = 0;
    ll r = 1e14;
    ll res = r;
    while(l <= r){
        ll mid = (r - l) / 2 + l;
        if(check(mid , v)){
            r = mid - 1;
            res = min(res , mid);
        }
        else{
            l = mid + 1;
        }
    }
    cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 