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
ll n , t , m , temp , temp2 ,p , q ,  r , root;

ll gcd(ll a ,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b , a%b);
}

void func(){
    cin>>m>>n;
    vector<ll> a;
    vector<ll> b;
    for(ll i = 0;i < m;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(ll i = 0;i < n;i++){
        cin>>temp;
        b.push_back(temp);
    }
    for(ll i = 0;i < n;i++){
        ll gcd_val = b[i] + a[0];
        for(ll j = 1,k = m - 1;j <= k;j++,k--){
            gcd_val = gcd(gcd_val , b[i] + a[j]);
            gcd_val = gcd(gcd_val , b[i] + a[k]);
            if(gcd_val == 1){
                break;
            }
           // cout<<gcd_val<<" "<<(a[i] + b[j])<<nl;
        }
        cout<<gcd_val<<" ";
    }
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 