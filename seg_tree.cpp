#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define INF 1000007
#define MAX (1 << 20)
#define EPS 1e-9
// #define PI acos(-1.0)
#define nl "\n"
#define F first
#define S second






//---------------parent code ------------------//


struct segtree {
    struct node {
        // initial values for leaves
        long long mx = 0;
        long long sum = 0;
        long long add = 0;

        void apply(int l, int r, long long v) {
            mx += v;
            sum += (r - l + 1) * v;
            add += v;
        }
    };

    static node unite(const node &a, const node &b) {
        node res;
        res.mx = max(a.mx, b.mx);
        res.sum = a.sum + b.sum;
        return res;
    }

    void push(int x, int l, int r) {
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        if (tree[x].add != 0) {
            tree[x + 1].apply(l, m, tree[x].add);
            tree[y].apply(m + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }

    void pull(int x, int y) { tree[x] = unite(tree[x + 1], tree[y]); }

    int n;
    vector<node> tree;

    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        build(x + 1, l, m);
        build(y, m + 1, r);
        pull(x, y);
    }

    template <class T>
    void build(int x, int l, int r, const vector<T> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        build(x + 1, l, m, v);
        build(y, m + 1, r, v);
        pull(x, y);
    }

    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        node res;
        if (rr <= m) {
            res = get(x + 1, l, m, ll, rr);
        } else {
            if (ll > m) {
                res = get(y, m + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, m, ll, rr), get(y, m + 1, r, ll, rr));
            }
        }
        pull(x, y);
        return res;
    }

    template <class T>
    void modify(int x, int l, int r, int ll, int rr, const T &v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v);
            return;
        }
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        push(x, l, r);
        if (ll <= m) {
            modify(x + 1, l, m, ll, rr, v);
        }
        if (rr > m) {
            modify(y, m + 1, r, ll, rr, v);
        }
        pull(x, y);
    }

    segtree(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }

    template <class T>
    segtree(const vector<T> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }

    node get(int ll, int rr) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }

    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }

    template <class T>
    void modify(int ll, int rr, const T v) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v);
    }

    int find_first(int ll, int rr, const function<bool(const node &)> &f, int x, int l, int r) {
        if (ll <= l && r <= rr && !f(tree[x])) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int m = (l + r) >> 1;
        int y = x + ((m - l + 1) << 1);
        int res = -1;
        if (ll <= m) {
            res = find_first(ll, rr, f, x + 1, l, m);
        }
        if (rr > m && res == -1) {
            res = find_first(ll, rr, f, y, m + 1, r);
        }
        pull(x, y);
        return res;
    }

    // calls all FALSE elements to the left of the sought position exactly once
    int find_first(int ll, int rr, const function<bool(const node &)> &f) {
        assert(0 <= ll && ll <= rr && rr <= n - 1);
        return find_first(ll, rr, f, 0, 0, n - 1);
    }
};

// Returns min(p | p<=rr && sum[ll..p]>=sum). If no such p exists, returns -1
int sum_lower_bound(segtree &t, int ll, int rr, long long sum) {
    long long sumSoFar = 0;
    return t.find_first(ll, rr, [&](const segtree::node &node) {
        if (sumSoFar + node.sum >= sum)
            return true;
        sumSoFar += node.sum;
        return false;
    });
}




//----------------end parent code -------------//

#define ll long long
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


vi adj[300005];
ll ans[300005];



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    segtree a(10);
    a.modify(0,5,5);
    cout<<a.get(0,0).mx<<nl;
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