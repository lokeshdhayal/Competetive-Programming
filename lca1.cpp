#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define ll long long
#define INF 1000007
#define MAX 100007
#define EPS 1e-9
// #define PI acos(-1.0)
#define nl "\n"
#define F first
#define S second
typedef vector<ll> vi;
typedef priority_queue<ll , vector<ll> , greater<ll> > pqmx;
typedef priority_queue<ll> pqmn;
typedef pair<ll , ll> pi;
typedef pair<ll , ll> ii;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector< pair<ll , ll> > vpi;
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define yeS(GOOD)      GOOD ? cout<<"YES\n" : cout<<"NO\n"
#define all(a) a.begin() , a.end()
#define pb push_back
#define ar array

constexpr int mod = (int)1e9 + 7;

ll binpow(ll a, ll b){ll res=1;a%=mod;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll binmul(ll a, ll b){ll res=0;a%=mod;while(b>0){if(b&1)res=(res + a)%mod;a=(a + a)%mod;b>>=1;}return res;}
ll area(pi a, pi b,pi c){return abs(a.F * b.S + b.F * c.S + c.F*a.S - a.S * b.F - b.S * c.F - c.S * a.F);}
ll gcd (ll a,ll b){if(b==0)return a;else return gcd (b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll min(ll a,ll b){if(a < b){return a;}return b;}
ll max(ll a,ll b){if(a > b){return a;}return b;}
double intlog(ll n ,ll base){return (double)log(n)/log(base);}

template <int mod>
struct modint {
    int value;
    modint(long long x = 0) { value = normalize(x); }
    int normalize(long long x) {if (x < -mod || x >= mod)x %= mod;
    if (x < 0)x += mod;return static_cast<int>(x);}
    explicit operator int() const { return value; }
    modint operator-() const { return modint(-value); }
    modint &operator+=(modint rhs) {if ((value += rhs.value) >= mod)value -= mod;return *this;}
    modint &operator-=(modint rhs) {if ((value -= rhs.value) < 0)value += mod;return *this;}
    modint &operator*=(modint rhs) {value = normalize(static_cast<long long>(value) * rhs.value);return *this;}
    modint &operator/=(modint rhs) { return *this *= modint(inverse(rhs.value, mod)); }
    int inverse(int a, int m) {int u = 0, v = 1;while (a != 0) {int t = m / a;m -= t * a;swap(a, m);u -= t * v;swap(u, v);}
        assert(m == 1);return u;}
    bool operator==(modint rhs) const { return value == rhs.value; }
    bool operator!=(modint rhs) const { return !(*this == rhs); }
    friend modint operator+(modint lhs, modint rhs) { return lhs += rhs; }
    friend modint operator-(modint lhs, modint rhs) { return lhs -= rhs; }
    friend modint operator*(modint lhs, modint rhs) { return lhs *= rhs; }
    friend modint operator/(modint lhs, modint rhs) { return lhs /= rhs; }
};

using mint = modint<mod>;


ll t , m , temp , temp2, root , p ,q , k , i , j , r , u , v , w,n;
 

ll depth[1005];

ll Sqt[1005][10];


void dfs(int i,vector<vector<int> > & adj,int par){
    for(int j : adj[i]){
        if(j == par)continue;
        depth[j] = depth[i] + 1;
        Sqt[j][0] = i;
        for(int k = 1;k < 10;k++){
            Sqt[j][k] = Sqt[Sqt[j][k-1]][k - 1];
        }
        dfs(j,adj,i);
    }
}



int get_lca(int p,int q){
    if(depth[p] < depth[q])return get_lca(q , p);
    int k = depth[p] - depth[q];
    for(int i = 9;i >= 0;i--){
        if((k & (1 << i))){
            p = Sqt[p][i];
        }
    }
    if(p == q)return p;
    for(int i = 9;i >= 0;i--){
        if(Sqt[p][i] != Sqt[q][i]){
            p = Sqt[p][i];
            q = Sqt[q][i];
        }
    }
    return Sqt[p][0];
}


map<int ,  vector<pair<int , int > >  > mp;

int ans[100000];

pair<int , vector<int> > * arr[1000];

void solve(int i,int q,vector<vector<int>> & adj){
    int mx = 0;
    int p = -1;
    for(int j : adj[i]){
        if(j == q)continue;
        solve(j,i,adj);
        if((int)arr[j]->S.size() > mx){
            p = j;
            mx = (int)arr[j]->S.size();
        }
    }
    if(p == -1){
        pair<int , vector<int> > a;
        a.F = 0;
        a.S.pb(0);
        arr[i] = &a;
    }
    else{
        arr[i] = arr[p];
        arr[i]->F++;
        arr[i]->S.pb(i);
    }
    for(int j : adj[i]){
        if(j == q || j == p)continue;
        for(int r : arr[j]->S){
            arr[i]->S.pb(1 + r + arr[j]->F - arr[i]->F);
        }
    }
    for(auto & j : mp[i]){
        int val = ;
        
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif

    cin>>n;
    n++;
    vector<vector<int>> adj(n);
    fr(i , n-1){
        cin>>p;
        adj[p].pb(i+1);
    }
    dfs(0,adj,-1);
    cin>>q;
    fr(i , q){
        cin>>u>>p;
        for(int i = 9;i >= 0;i--){
            if((p & (1 << i))){
                u = Sqt[u][i];
            }
        }
        mp[u].pb({u,i});
    }
    solve(0,-1,adj);

#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}