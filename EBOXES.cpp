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

void func(){
    ll N , K , lll , F;
    cin>>N>>K>>lll>>F;
    ll p = F - N;
    ll res = F + (p / (K - 1));
    cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 