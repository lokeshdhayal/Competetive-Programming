#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define ll long long
#define INF 1000007
#define MAX (1 << 20)
#define EPS 1e-9
// #define PI acos(-1.0)
#define nl "\n"
#define F first
#define S second
typedef vector<ll> vi;
typedef priority_queue<ll , vector<ll> , greater<ll> > pqmx;
typedef priority_queue<ll> pqmn;
typedef pair<ll , ll> pi;
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
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_add(ll a, ll b) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll binpow(ll a, ll b,ll mod){ll res=1;a%=mod;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll binmul(ll a, ll b){ll res=0;a%=mod;while(b>0){if(b&1)res=(res + a)%mod;a=(a + a)%mod;b>>=1;}return res;}
ll area(pi a, pi b,pi c){return abs(a.F * b.S + b.F * c.S + c.F*a.S - a.S * b.F - b.S * c.F - c.S * a.F);}
ll gcd (ll a,ll b){if(b==0)return a;else return gcd (b, a % b);}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll min(ll a,ll b){if(a < b){return a;}return b;}
ll max(ll a,ll b){if(a > b){return a;}return b;}
double intlog(ll n ,ll base){return (double)log(n)/log(base);}




ll t , m , temp , temp2, root ,q , k , i , j , r , u , v , w,n , l , p;


//------------- Parent Code Start here ------------------//

const int MAX_NODES = 200000;
int parent[MAX_NODES];
unsigned pre_order[MAX_NODES];
unsigned I[MAX_NODES];
int head[MAX_NODES];
unsigned A[MAX_NODES];
unsigned Time;

unsigned lowest_one_bit(unsigned x) {
    return x & -x;
}

unsigned highest_one_bit(unsigned x) {
    return x ? 1u << (31 - __builtin_clz(x)) : 0;
}

void dfs1(const vector<vector<int>> &tree, int u, int p) {
    parent[u] = p;
    I[u] = pre_order[u] = Time++;
    for (int v : tree[u]) {
        if (v == p)
            continue;
        dfs1(tree, v, u);
        if (lowest_one_bit(I[u]) < lowest_one_bit(I[v])) {
            I[u] = I[v];
        }
    }
    head[I[u]] = u;
}

void dfs2(const vector<vector<int>> &tree, int u, int p, unsigned up) {
    A[u] = up | lowest_one_bit(I[u]);
    for (int v : tree[u]) {
        if (v == p)
            continue;
        dfs2(tree, v, u, A[u]);
    }
}

// initialization in O(n)
void init_lca(const vector<vector<int>> &tree, int root) {
    Time = 0;
    dfs1(tree, root, -1);
    dfs2(tree, root, -1, 0);
}

int enter_into_strip(int x, int hz) {
    if (lowest_one_bit(I[x]) == hz)
        return x;
    int hw = highest_one_bit(A[x] & (hz - 1));
    return parent[head[(I[x] & -hw) | hw]];
}

// lca in O(1)
int lca(int x, int y) {
    int hb = I[x] == I[y] ? lowest_one_bit(I[x]) : highest_one_bit(I[x] ^ I[y]);
    int hz = lowest_one_bit(A[x] & A[y] & -hb);
    int ex = enter_into_strip(x, hz);
    int ey = enter_into_strip(y, hz);
    return pre_order[ex] < pre_order[ey] ? ex : ey;
}

void init_rmq(const vector<int> &values) {
    // build Cartesian Tree
    int n = values.size();
    int root = 0;
    vector<int> p(n, -1);
    for (int i = 1; i < n; i++) {
        int prev = i - 1;
        int next = -1;
        while (values[prev] > values[i] && p[prev] != -1) {
            next = prev;
            prev = p[prev];
        }
        if (values[prev] > values[i]) {
            p[prev] = i;
            root = i;
        } else {
            p[i] = prev;
            if (next != -1) {
                p[next] = i;
            }
        }
    }
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; ++i)
        if (p[i] != -1)
            tree[p[i]].push_back(i);
    init_lca(tree, root);
}


//----------------parent coder end here --------------- //

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}




//Try to think every possible test case and then try to implement
//Write Down the equation and try to solve it
//Have done it before then just implement without thinking 

//Look deep into your soul, into the dark and foggy mist of your memories

//Number Theory  -> could solve the question
//BigManupulation -> can't solve()
//Graph -> similiar problem going to face in graph alsogvgsfs