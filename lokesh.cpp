//https://oeis.org/search?q=0%2C0%2C1%2C2%2C4%2C6&language=english&go=Search
//https://smallpdf.com/result#r=dc43c99933feaa1c7f3a2f2e2036bc6a&t=pdf-to-word
#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define ll long long
#define INF 1000007
#define MAX 500007
#define EPS 1e-9
#define PI acos(-1.0)
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
ll mod = LLONG_MAX;
ll binpow(ll a, ll b){ll res=1;a%=mod;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll binmul(ll a, ll b){ll res=0;a%=mod;while(b>0){if(b&1)res=(res + a)%mod;a=(a + a)%mod;b>>=1;}return res;}
ll area(pi a, pi b,pi c){return abs(a.F * b.S + b.F * c.S + c.F*a.S - a.S * b.F - b.S * c.F - c.S * a.F);}
ll gcd (ll a,ll b){if(b==0)return a;else return gcd (b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll min(ll a,ll b){if(a < b){return a;}return b;}
ll max(ll a,ll b){if(a > b){return a;}return b;}
double intlog(ll n ,ll base){return (double)log(n)/log(base);}
double DEG_to_RAD(double d) { return d * PI / 180.0; }
double RAD_to_DEG(double r) { return r * 180.0 / PI; }

ll n , t , m , temp , temp2, root , p ,q , k , i , j , r , u , v , w;
struct comp { 
    bool operator()( pair<int, int> const& a, pair<int, int> const& b) { 
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    } 
};

bool is_valid(int i , int j , vector<vc> & a){
    if(i < 0 || j < 0 || i >= n || j >= m){
        return false;
    }
    return a[i][j] == '.';
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    cin>>n>>m;
    cin>>p>>q;
    vector<vc> a(n + 1, vc(m + 1));
    fr(i , n){fr(j , m)cin>>a[i][j];}
    p--;q--;
    ll res = 0;
    if(a[p][q] == '.')res++;
    int i = p;int j = q;
    int k = 1;
    while(is_valid(i - k, j , a)){k++;res++;}
    k = 1;
 //   cout<<"yes"<<nl;
    while(is_valid(i , j - k , a)){k++;res++;}
    k = 1;
    while(is_valid(i + k, j , a)){k++;res++;}
    k = 1;
    while(is_valid(i , j + k , a)){k++;res++;}
    cout<<res<<nl;
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}