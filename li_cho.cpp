//auto r = s.lower_bound({p , std::numeric_limits<int>::min()});
#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define ll long long
#define INF 10007
#define MAX (1 << 20)
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

ll t , m , temp , temp2, root ,q , k , i , j , r , u , v , w,n , l , p,x;


using T = long long;

struct Line {
    T a, d;

    T eval(T x) { return a * x + d; }
};

struct Node {
    Line line;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(Line line) : line(line) {}

    void add_line(Line nline, T l, T r) {
        T m = (l + r) / 2;
        bool left_smaller = nline.eval(l) < line.eval(l);
        bool mid_smaller = nline.eval(m) < line.eval(m);
        if (mid_smaller) {
            swap(line, nline);
        }
        if (r - l == 1) {
            return;
        }
        if (left_smaller != mid_smaller) {
            if (left == nullptr)
                left = new Node(nline);
            else
                left->add_line(nline, l, m);
        } else {
            if (right == nullptr)
                right = new Node(nline);
            else
                right->add_line(nline, m, r);
        }
    }

    T get_min(T x, T l, T r) {
        if (r - l > 1) {
            T m = (l + r) / 2;
            if (x < m && left != nullptr) {
                return min(line.eval(x), left->get_min(x, l, m));
            }
            if (x >= m && right != nullptr) {
                return min(line.eval(x), right->get_min(x, m, r));
            }
        }
        return line.eval(x);
    }
};

struct LiChaoTree {
    T minx;
    T maxx;
    Node *root;

    LiChaoTree(T minx, T maxx) : minx(minx), maxx(maxx) { root = new Node({0, numeric_limits<T>::max() / 2}); }

    void add_line(Line line) { root->add_line(line, minx, maxx + 1); }

    T get_min(T x) { return root->get_min(x, minx, maxx + 1); }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    ll c;
    cin>>n>>c;
    vi a(n);
    fr(i , n){
        cin>>a[i];
    }
    LiChaoTree p(1,1e9);
    vi dp(n , 0);
    p.add_line({-2*a[0],c + a[0]*a[0]});
    rep(i , 1 , n){
        dp[i] = p.get_min(a[i]) + a[i] * a[i];
        p.add_line({-2*a[i],c + dp[i] + a[i]*a[i]});
        //cout<<dp[i]<<" ";
    }
    cout<<dp[n - 1]<<'\n';
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}
//   k ^ a >= b + 1
//
//   A  AAAACBAAA   A -> 7 AA -> 5 AAA -> 3 AAAA -> 1 5  AABCA


//Try to think every possible test case and then try to implement
//Write Down the equation and try to solve it
//Have done it before then just implement without thinking 

//Look deep into your soul, into the dark and foggy mist of your memories

//Number Theory  -> could solve the question
//BigManupulation -> can't solve()
//Graph -> similiar problem going to face in graph 