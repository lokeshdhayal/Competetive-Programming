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


void func(){
    cin>>n;
    vi a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a.begin() , a.end() , greater<ll>());
    ll p = a[0];
    ll need = 0;
    for(int i = 0;i < a.size() - 1;i++){
        need += p - a[i];
    }
   // cout<<need<<" "<<a[a.size() - 1]<<'\n';
    if(need >= a[a.size() - 1]){
        cout<<(need - a[a.size() - 1])<<'\n';
        return;
    }
    p = a[a.size() - 1];
    p -= need;
    if(p % (n - 1) == 0){
        cout<<0<<'\n';
        return;
    }
    int ans = a.size() - 1 - (p % (n - 1));
    cout<<ans<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 