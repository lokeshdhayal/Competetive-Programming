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
ll n , t , m , temp , temp2, root , r , p ,q , k;

bool comp(pi a , pi b){
    return (a.first > b.first);
}


void func(){
    cin>>n;
    vector<pi> a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin() , a.end() , comp);
    vi res(n , 0);
    vector<bool> vis(n , false);
    for(int i = 0;i < n;i++){
        for(int j = min(n , a[i].second) - 1;j >= 0;j--){
            if(vis[j] == false){
                res[j] = a[i].first;
                vis[j] = true;
                break;
            }
        }
    }
    ll result = 0;
    for(int i = 0;i < n;i++){
        result += res[i];
    }
    cout<<result<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 