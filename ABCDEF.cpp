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

void input(vi & a , int n){
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
}

ll n , t , m , temp , temp2 ,p , q ,  r , root , k;

void func(){
    cin>>n;
    vi a(n);
    input(a , n);
    map<ll , int> hashmap;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                hashmap[a[i]*a[j] + a[k]]++;
            }
        }
    }
    ll res = 0;
    for(int i = 0;i < n;i++){
        if(a[i] == 0){
            continue;
        }
        for(int j = 0;j < n;j++){
            for(int k = 0;k < n;k++){
                int l = a[i]*(a[j] + a[k]);
                if(hashmap.find(l) != hashmap.end()){
                    res += hashmap[l];
                }
            }
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