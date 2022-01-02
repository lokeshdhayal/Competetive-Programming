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

constexpr int mod = (int)1e9;

ll binpow(ll a, ll b,ll mod){ll res=1;a%=mod;while(b>0){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return res;}
ll binmul(ll a, ll b){ll res=0;a%=mod;while(b>0){if(b&1)res=(res + a)%mod;a=(a + a)%mod;b>>=1;}return res;}
ll area(pi a, pi b,pi c){return abs(a.F * b.S + b.F * c.S + c.F*a.S - a.S * b.F - b.S * c.F - c.S * a.F);}
ll gcd (ll a,ll b){if(b==0)return a;else return gcd (b, a % b);}
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
ll min(ll a,ll b){if(a < b){return a;}return b;}
ll max(ll a,ll b){if(a > b){return a;}return b;}
double intlog(ll n ,ll base){return (double)log(n)/log(base);}


ll t , m , temp , temp2, root , p ,q , k , i , j , r , u , v , w,n;

string s;


struct Node{
    int left_open;
    int right_open;
    int ans;
    Node(){
        ans = 0;
        left_open = 0;
        right_open = 0;
    }
};

vi a;

Node S[4* 1000010];


void build(int si,int ss,int se){
    if(ss == se){
        if(s[ss] == ')'){
            S[si].left_open++;
        }
        else{
            S[si].right_open++;
        }
    }
    else{
        int mid = (se + ss)/2;
        build(2*si , ss , mid);
        build(2*si + 1,mid+1,se);
        S[si].ans += S[2*si].ans + S[2*si + 1].ans;
        int u = S[2*si].right_open;
        int v = S[2*si + 1].left_open;
        S[si].ans += min(u , v);
        if(u > v){
            S[si].left_open = S[2*si].left_open;
            S[si].right_open = S[2*si + 1].right_open + u - v;
        }
        else if(v > u){
            S[si].left_open = S[2*si].left_open + v - u;
            S[si].right_open = S[2*si + 1].right_open;
        }
        else{
            S[si].left_open = S[2*si].left_open + v - u;
            S[si].right_open = S[2*si + 1].right_open;
        }
    }
}

Node query(int l,int r , int si,int ss,int se){
    if(ss >= l && se <= r)return S[si];
    if(ss > r || se < l){
        return Node();
    }
    int mid = (ss + se)/2;
    Node left = query(l,r,2*si , ss , mid);
    Node right = query(l,r,2*si + 1,mid+1,se);
    Node p;
    p.ans += left.ans + right.ans;
    int u = left.right_open;
    int v = right.left_open;
    p.ans += min(u , v);
    if(u > v){
        p.left_open = left.left_open;
        p.right_open = right.right_open + u - v;
    }
    else if(v > u){
        p.left_open = left.left_open + v - u;
        p.right_open = right.right_open;
    }
    else{
        p.left_open = left.left_open + v - u;
        p.right_open = right.right_open;
    }
    return p;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    cin>>s;
    n = (int)s.size();
    build(1,0,n-1);
    cin>>t;
    while(t--){
        int u , v;
        cin>>u>>v;
        cout<<query(u - 1, v - 1, 1 , 0 , n - 1).ans * 2<<nl;
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}