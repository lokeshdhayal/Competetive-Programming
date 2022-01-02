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


ll t , m , temp , temp2, root , p ,q , k , i , j , r , u , v , w,n;

struct Node{
    ll sum;
    ll pre;
    ll suff;
    ll suff_el;
    ll pre_el;
    Node(){
        pre = 1;
        suff = 1;
        sum = 1;
    }
};

vi a;

Node S[4* 50010];


void build(int si,int ss,int se){
    if(ss == se){
        S[si].sum = 1;
        S[si].pre = 1;
        S[si].suff = 1;
        S[si].suff_el = a[i];
        S[si].pre_el = a[i];
    }
    else{
        int mid = (se + ss)/2;
        build(2*si , ss , mid);
        build(2*si + 1,mid+1,se);
        S[si].sum = S[2*si].sum + S[2*si + 1].sum;
        S[si].pre = max(S[2*si].pre , S[2*si].sum + S[2*si + 1].pre);
        S[si].suff = max(S[2*si + 1].suff , S[2*si + 1].sum + S[2*si].suff);
        S[si].mx = max(S[2*si].mx,S[2*si + 1].mx);
        S[si].mx = max(S[si].mx ,S[2*si].suff + S[2*si + 1].pre);
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
    p.sum = left.sum + right.sum;
    p.pre = max(left.pre , left.sum + right.pre);
    p.suff = max(right.suff , right.sum + left.suff);
    p.mx = max(left.mx , right.mx);
    p.mx = max(p.mx , left.suff + right.pre);
    p.mx = max(p.mx , left.sum + right.pre);
    p.mx = max(p.mx , left.suff + right.sum);
    return p;
}


void update(int pos,int val,int si,int ss,int se){
    if(ss == se){
        S[si].sum = val;
        S[si].pre = val;
        S[si].suff = val;
        S[si].mx = val;
        a[pos] = val;
    }
    else{
        int mid = (se + ss)/2;
        if(mid >= pos)update(pos,val,2*si , ss , mid);
        else update(pos,val,2*si + 1,mid+1,se);
        S[si].sum = S[2*si].sum + S[2*si + 1].sum;
        S[si].pre = max(S[2*si].pre , S[2*si].sum + S[2*si + 1].pre);
        S[si].suff = max(S[2*si + 1].suff , S[2*si + 1].sum + S[2*si].suff);
        S[si].mx = max(S[2*si].mx,S[2*si + 1].mx);
        S[si].mx = max(S[si].mx ,S[2*si].suff + S[2*si + 1].pre);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    cin>>n;
    ll lok;
    a.assign(n , 0);
    fr(i , n){
        cin>>a[i];
    }
    build(1,0,n-1);
    cin>>t;
    while(t--){
        cin>>lok>>p>>q;
        if(lok == 0){
            update(p-1,q,1,0,n-1);
            continue;
        }
        Node lok = query(p-1,q-1,1,0,n-1);
        cout<<lok.mx<<nl;
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}