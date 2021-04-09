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
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , p ,q , k;
ll BITS[300001];

void update(int idx){
    while(idx <= 300000){
        BITS[idx]++;
        idx += (idx & -idx);
    }
}

ll find_sum(int idx){
    ll res = 0;
    while(idx > 0){
        res += BITS[idx];
        idx -= (idx & -idx);
    }
    return res;
}


void func(){
    cin>>n;
    vi a(n);
    set<ll> s;
    for(int i = 1;i <= n;i++){
        cin>>temp;
        if(s.find(temp) == s.end()){
            update(i);
            s.insert(temp);
        }
    }
    cin>>p;
    ll l;
    ll r;
    while(p--){
        cin>>l>>r;
        ll res = 0;
        if(l == 1){
            res = find_sum(r);
        }
        else{
            res = find_sum(r) - find_sum(l-1);
            cout<<find_sum(r)<<" "<<find_sum(l-1)<<'\n';
        }
        cout<<res<<'\n';
    }
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 