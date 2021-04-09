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
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    if(b == d){
        cout<<abs(c - a)<<nl;
        return;
    }
    if(a == c){
        cout<<abs(d - b)<<nl;
        return;
    }
    cout<<(abs(d - b) +  abs(c- a) + 2)<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 