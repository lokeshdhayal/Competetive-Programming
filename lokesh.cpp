//auto r = s.lower_bound({p , std::numeric_limits<int>::min()});
//https://mzhang2021.github.io/cp-blog/index.html
//https://codeforces.com/bestRatingChanges/6118990
#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;
#define ll long long
#define INF 10007
#define MAX 200005
#define EPS 1e-9
#define PI acos(-1.0)
#define nl "\n"
#define F first
#define S second
typedef pair<ll , ll> pi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector< pair<ll , ll> > vpi;
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
#define yeS(GOOD)      GOOD ? cout<<"YES\n" : cout<<"NO\n"
#define all(a) a.begin() , a.end()
#define pb push_back
#define ar array

ll mod = (ll)1e9+7;
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
string bin(int n){if(n==0)return "0";string s;while(n){if(n%2){s='1'+s;}else{s='0'+s;}n/=2;}return s;}

ll t , m , temp , temp2, k , i , j , r , u , l , n,q,v,p;
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
    cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
    cin >> p.first;
    return cin >> p.second;
}
const int N = 1005;

int a[N],b[N];

ll solve(int i,int sum1,int sum2){
    if(i == n){
        if(sum1 == 0){
            return INT_MIN;
        }
        return sum2*k == sum1 ? 0 : INT_MIN;
    }
    ll ans = INT_MIN;
    ans=max(ans,solve(i+1,sum1,sum2));
    ans=max(ans,solve(i+1,sum1+a[i],sum2+b[i])+a[i]);
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    ll x,y,a;
    cin>>a>>x>>y;
    if(y%a == 0){
        cout<<-1<<'\n';return 0;
    }
    if(y < a){
        int mx = (a-1)/2;
        if(abs(x) > mx){
            cout<<-1<<'\n';
        }
        else{
            cout<<1<<'\n';
        }
        return 0;
    }
    ll ans = 1;
    y-=a;
    ans += (y/(2*a))*3;
    ans++;
    //cout<<y/(2*a)<<" "<<ans<<'\n';
    if(y%(2*a) > a){
        if(x == 0 || abs(x) >= a){
            cout<<-1<<'\n';return 0;
        }
        ans++;
        if(x > 0)ans++;
    }
    else{
        if(abs(x) > (a-1)/2){
            cout<<-1<<'\n';return 0;
        }
    }
    cout<<ans<<'\n';
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
//Look deep into your 1oul, into the dark and foggy mist of your memories


//Number Theory  -> could solve the question
//BigManupulation -> can't solve()
//Graph -> similiar problem going to face in graph 


/*
#Sigma Rule :-
        If you are not finding any mistake in code then there is mistake in your logic.

*/