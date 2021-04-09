#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://o...content-available-to-author-only...s.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

bool comp(pi a , pi b){
    return (a.first > b.first);
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


void func(){
    cin>>n;
    vi a(n);
    map<int , int> hashmap;
    ll res = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        hashmap[a[i]]++;
    }
    for(int i = 0;i < n;i++){
        bool flag = false;
        if(hashmap[a[i]] > 1){
            flag = true;
        }
        p = binpow(a[i] , 0);
        if(hashmap.find(p) != hashmap.end() && a[i] != 1){
            flag = true;
        }
        if(flag == false && a[i] != 1){
            p = binpow(a[i] , 2);
            for(int j = 2;1000000 >= p;j++,p = binpow(a[i] , j)){
                if(hashmap.find(p) != hashmap.end()){
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            res++;
        }
    }
    cout<<"Case "<<k<<": "<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        k++;
        func();
    }
} 