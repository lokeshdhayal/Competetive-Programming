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

bool comp(pi a ,pi b){
    return (a.second < b.second) || ((a.second == b.second) && a.first < b.first);
}

void func(){
    vector<pi> a;
    for(int i = 0;i < n;i++){
        cin>>p>>q;
        a.push_back({ p , q });
    }
    sort(a.begin() , a.end() , comp);
    vector<ll> dp(n , 1);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(a[i].first >= a[j].second){
                dp[i] = (dp[i] + dp[j])%100000000;
            }
        }
     //   cout<<dp[i]<<" ";
    }
    ll res = 0;
    for(int i = 0;i < dp.size();i++){
        res += dp[i];
    }
    string s = to_string(res);
    while(s.size() < 8){
        s = '0' + s;
    }
    cout<<s<<'\n';
}



int main(){
    cin>>n;
    while(n != -1){
        func();
        cin>>n;
    }
} 