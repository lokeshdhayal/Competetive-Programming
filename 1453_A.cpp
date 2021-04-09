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
    cin>>a[0];
    ll count_val = 0;
    for(int i = 1;i < n;i++){
        cin>>a[i];
        count_val += abs(a[i] - a[i - 1]);
    }
    ll p = abs(a[0] - a[1]);
    p = max(p , abs(a[n - 1] - a[n - 2]));
    for(int i = 1;i < n - 1;i++){
        p = max(p , abs(abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i - 1])));
    }
    count_val -= p;
    cout<<count_val<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 