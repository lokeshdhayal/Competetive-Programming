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



ll t , m , temp , temp2, root , p ,q , k , i , j , r , u , v , w,n;
 

int depth[300005];

int Sqt[300005][32];
int Sqt1[300005][32];
int Sqt2[300005][32];

void dfs(int i,vector<vpi> & adj,int par){
    for(auto j : adj[i]){
        if(j.F == par)continue;
        depth[j.F] = depth[i] + 1;
        Sqt[j.F][0] = i;
        for(int k = 1;k < 30;k++){
            Sqt[j.F][k] = Sqt[Sqt[j.F][k-1]][k - 1];
        }
        dfs(j.F,adj,i);
    }
}


void dfs1(int i,vector<vpi> & adj,int par){
    for(auto j : adj[i]){
        if(j.F == par)continue;
        Sqt1[j.F][0] = j.S;
        for(int k = 1;k < 30;k++){
            Sqt1[j.F][k] = max(Sqt1[Sqt[j.F][k-1]][k - 1] , Sqt1[j.F][k - 1]);
        }
        dfs1(j.F,adj,i);
    }
}

void dfs2(int i,vector<vpi> & adj,int par){
    for(auto j : adj[i]){
        if(j.F == par)continue;
        Sqt2[j.F][0] = j.S;
        for(int k = 1;k < 30;k++){
            Sqt2[j.F][k] = min(Sqt2[Sqt[j.F][k-1]][k - 1] , Sqt2[j.F][k - 1]);
        }
        dfs2(j.F,adj,i);
    }
}

int get_lca(int p,int q){
    if(depth[p] < depth[q])return get_lca(q , p);
    int k = depth[p] - depth[q];
    for(int i = 30;i >= 0;i--){
        if((k & (1 << i))){
            p = Sqt[p][i];
        }
    }
    if(p == q)return p;
    for(int i = 30;i >= 0;i--){
        if(Sqt[p][i] != Sqt[q][i]){
            p = Sqt[p][i];
            q = Sqt[q][i];
        }
    }
    return Sqt[p][0];
}



class UnionFind {
private: vi p, rank;
public:
    UnionFind(int N) { rank.assign(N, 0);
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    void unionSet(int i, int j) {if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x;
        else { p[x] = y;
            if (rank[x] == rank[y]) rank[y]++; }
        } 
    } 
    int count_val(){
        ll res = 0;
        for(int i = 0;i < p.size();i++){if(p[i] == i)res++;}
        return res;
    }
};


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    cin>>n>>m>>k;
    vi arr(m);
    fr(i , m){
        cin>>arr[i];
    }
    vector<vector<int> > adj(n);
    vector<pair<int , pair<int , int> > > a(m),b(m);
    fr(i , n - 1){
        cin>>a[i].S.F>>a[i].S.S>>a[i].F;
        a[i].S.F--;
        a[i].S.S--;
        b[i] = a[i];
    }
    dfs(0,adj,-1);
    dfs1(0,adj,-1);
    fr(i , m){
        int lca = get_lca(b[i].S.F , b[i].S.S);
        //cout<<lca<<" "<<b[i].S.F<<" "<<b[i].S.S<<'\n';
        int res = 0;
        int p = b[i].S.F;
        int q = b[i].S.S;
        int k = depth[p] - depth[lca];
        for(int i = 30;i >= 0;i--){
            if((k & (1 << i))){
                res = max(res , Sqt1[p][i]);
                p = Sqt[p][i];
            }
        }

        k = depth[q] - depth[lca];
        for(int i = 30;i >= 0;i--){
            if((k & (1 << i))){
                res = max(res , Sqt1[q][i]);
                q = Sqt[q][i];
            }
        }
        cout<<(result - res + b[i].F)<<'\n';
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}

/*

int ans[100005];
int depth[300005];
int Sqt[300005][32];
int Sqt1[300005][32];
void dfs1(int i,int p){
    for(int j : G[i]){
        if(j==p)continue;
        Sqt[j][0] = i;
        Sqt1[j][0] = ans[j];
        for(int k = 1;k < 32;k++){
            Sqt[j][k] = Sqt[Sqt[j][k-1]][k-1];
            Sqt1[j][k] = Sqt1[j][k-1]+Sqt1[Sqt[j][k-1]][k-1];
        }
        depth[j]=1+depth[i];
        dfs1(j,i);
    }
}

int lca(int i,int j){
    if(i == j)return ans[i];
    if(depth[i] > depth[j])return lca(j,i);
    int k = depth[j] - depth[i];
    int res = 0;
    for(int p = 30;p >= 0;p--){
        if((k & (1 << p))){
            res += Sqt1[j][p];
            j = Sqt[j][p];
        }
    }
    if(i == j){
        res += ans[j];
        return res;
    }
    for(int k = 30;k >= 0;k--){
        if(Sqt[i][k] != Sqt[j][k]){
            res += Sqt1[i][k];
            res += Sqt1[j][k];
            i = Sqt[i][k];
            j = Sqt[j][k];
        }
    }
    res += Sqt1[i][0] + Sqt1[j][0] + ans[Sqt[j][0]];
    return res;
}

*/