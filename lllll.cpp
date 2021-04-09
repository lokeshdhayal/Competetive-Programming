#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000007
#define MAX 500007
#define nl "\n"
#define F first
#define S second
typedef vector<int> vi;
typedef priority_queue<ll , vector<ll> , greater<ll> > pqmx;
typedef priority_queue<ll> pqmn;
typedef pair<ll , ll> pi;
typedef vector< pair<int , int> > vpi;
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define yeS(GOOD)      GOOD ? cout<<"YES\n" : cout<<"NO\n"
#define all(a) a.begin() , a.end()
#define pb push_back
#define ar array
ll mod = 1000000007;
ll binpow(ll a, ll b){ll res=1;a%=mod;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll gcd (ll a,ll b){if(b==0)return a;else return gcd (b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll n , t , m , temp , temp2, root , p ,q , k , i , j;
struct comp { 
    bool operator()( pair<int, int> const& a, pair<int, int> const& b) { 
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    } 
};

ll ask_xor(ll a , ll b){
    cout<<"XOR "<<a<<" "<<b<<'\n';
    cin>>temp;
    return temp;
}
ll ask_or(ll a , ll b){
    cout<<"OR "<<a<<" "<<b<<'\n';
    cin>>temp;
    return temp;
}

ll ask_and(ll a , ll b){
    cout<<"AND "<<a<<" "<<b<<'\n';
    cin>>temp;
    return temp;
}


void func(){
    cin>>n>>p;
    cout<<n * p<<'\n';
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    t = 1;
    while(t--){
        func();
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}