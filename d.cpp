#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define ll long long
#define INF 10007
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
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}


class SegmentTree {
private: vi st, A , lazy;
int n;
int left (int p) { return p << 1; }
int right(int p) { return (p << 1) + 1; }
void build(int p, int L, int R) {if (L == R) st[p] = A[L];else {
    build(left(p) , L , (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R );
    ll p1 = st[left(p)], p2 = st[right(p)];
    st[p] = max(p1 , p2);}
    }
ll rmq(int p, int L, int R, int i, int j) {if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st[p];
    if(lazy[p] != -1 && 2*p < lazy.size()){
        int si = p;
        lazy[2*si] = lazy[si];
        lazy[2*si + 1] = lazy[si];
        st[2*si] = lazy[si];
        st[2*si + 1] = lazy[si];
        lazy[si] = -1;
    }
    ll p1 = rmq(left(p) , L , (L+R) / 2, i, j);
    ll p2 = rmq(right(p), (L+R) / 2 + 1, R , i, j);
    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return max(p1 , p2);
}
void update(int si , int ss , int se , int pos , ll val){
    if(ss == se){
        st[si] = val;
        A[pos] = val;
    }
    else{
        if(lazy[si] != -1 && 2*si < lazy.size()){
            lazy[2*si] = lazy[si];
            lazy[2*si + 1] = lazy[si];
            st[2*si] = lazy[si];
            st[2*si + 1] = lazy[si];
            lazy[si] = -1;
        }
        int k = (ss + se) / 2;
        if(pos <= k){
            update(2*si , ss , k , pos , val);
        }
        else{
            update(2 * si + 1 , k + 1 , se , pos , val);
        }
        ll p1 = st[2*si];
        ll p2 = st[2*si + 1];
        st[si] = max(p1 , p2);
    }
}

ll modify(int p , int L , int R, int i , int j , int val){
    if (i > R || j < L) return -1;
    if (L >= i && R <= j){ 
        st[p] = val;
        lazy[p] = val;
        return st[p];
    }
    if(lazy[p] != -1 && 2*p < lazy.size()){
        int si = p;
        lazy[2*si] = lazy[si];
        lazy[2*si + 1] = lazy[si];
        st[2*si] = lazy[si];
        st[2*si + 1] = lazy[si];
        lazy[si] = -1;
    }
    ll p1 = modify(left(p) , L , (L+R) / 2, i, j , val);
    ll p2 = modify(right(p), (L+R) / 2 + 1, R , i, j , val);
    if (p1 == -1) return st[p] = p2;
    if (p2 == -1) return st[p] = p1;
    return st[p] = max(p1 , p2);
}

public:
    SegmentTree(const vi &_A) {A = _A; n = (int)A.size();
        st.assign(4 * n, 0);
        lazy.assign(4 * n , -1);
        build(1, 0, n - 1);
    }
    ll rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }
    void update(int i , ll val){
        update(1 , 0 , n - 1 , i , val);
    }
    ll modify(int i , int j , ll val){
        return modify(1 , 0 , n - 1 , i , j , val);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    cin>>n>>m;
    set<int> s;
    vector<vector<pair<int , int>> > a(n);
    fr(i , m){
        ll l , r;
        cin>>p>>l>>r;
        p--;
        a[p].pb({l,r});
        s.insert(l);
        s.insert(r);
    }
    vi arr;
    for(int i : s){
        arr.pb(i);
    }
    vi lok((int)arr.size(),0);
    SegmentTree sg(lok);
    int ans = 0;
    vector<int> dp(n);
    fr(i , n){
        int mx = 1;
        for(auto & j : a[i]){
            int val1 = lower_bound(all(arr),j.F)-arr.begin();
            int val2 = lower_bound(all(arr),j.S)-arr.begin();
            mx = max(mx , sg.rmq(val1,val2)+1);
        }
        for(auto & j : a[i]){
            int val1 = lower_bound(all(arr),j.F)-arr.begin();
            int val2 = lower_bound(all(arr),j.S)-arr.begin();
            sg.modify(val1,val2,mx);
        }
        dp[i] = mx;
        ans = max(ans,mx);
    }
    cout<<n - ans<<'\n';
    vi result;
    for(int i = n-1;i>=0;i--){
        if(dp[i]==ans){
            ans--;
            continue;
        }
        result.pb(i+1);
    }
    reverse(all(result));
    for(int i : result){
        cout<<i<<" ";
    }
    cout<<'\n';
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