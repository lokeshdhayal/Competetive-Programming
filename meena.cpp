//https://oeis.org/search?q=0%2C0%2C1%2C2%2C4%2C6&language=english&go=Search
#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long
#define INF 1000007
#define MAX 500007
#define nl "\n"
#define F first
#define S second
typedef vector<ll> vi;
typedef priority_queue<ll , vector<ll> , greater<ll> > pqmx;
typedef priority_queue<ll> pqmn;
typedef pair<ll , ll> pi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector< pair<int , int> > vpi;
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define yeS(GOOD)      GOOD ? cout<<"YES\n" : cout<<"NO\n"
#define all(a) a.begin() , a.end()
#define pb push_back
#define ar array
ll mod = 1000000007;
ll binpow(ll a, ll b){ll res=1;a%=mod;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll area(pi a, pi b,pi c){return abs(a.F * b.S + b.F * c.S + c.F*a.S - a.S * b.F - b.S * c.F - c.S * a.F);}
ll gcd (ll a,ll b){if(b==0)return a;else return gcd (b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll n , t , m , temp , temp2, root , p ,q , k , i , j , r ;
struct comp { 
    bool operator()( pair<int, int> const& a, pair<int, int> const& b) { 
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    } 
};
string s;
ll res = 0;
ll val = 0;
void rec(ll d){
    i++;
    if(d > val){
        res = p;
        val = d;
    }
    if(s[i] == '1'){
        p++;
        rec(d + 1);
        rec(d + 1);
    }
}

void func(){
    cin>>s;
    p = 0;
    res = 0;
    val = 0;
    i = -1;
    rec(0);
    cout<<res<<'\n';
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    while(cin>>n){
        func();
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}
