#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;


void func(){
    cin>>n;
    vector<vi> a(n , vi(2));
    ll p = 0;
    ll q = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i][0]>>a[i][1];
        p = max(p , a[i][0]);
        q = max(q , a[i][1]);
    }
    ll r = max(p , q);
    ll min_val = LONG_MAX;
    map<ll , ll> hash;
    for(int i = 0;i <= p;i++){
        for(int j = 0;j <= q;j++){
            ll sum_val = 0;
            for(int k = 0;k < n;k++){
                sum_val += abs(a[k][0] - i) + abs(a[k][1] - j);
            }
            min_val = min(min_val , sum_val);
            hash[sum_val]++;
        }
    }
    cout<<hash[min_val]<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 