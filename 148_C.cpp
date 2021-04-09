#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define F first
#define S second
#define pb(a) push_back(a)
typedef vector<ll> vi;
typedef priority_queue<ll , vector<ll> , greater<ll>()> pqmx;
typedef priority_queue<ll> pqmn;
typedef pair<ll , ll> pi;
typedef vector< pair<int , int> > vpi;
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
int n , t , m , temp , temp2, root , p ,q , k , i , j;

struct comp { 
    bool operator()( pair<int, int> const& a, pair<int, int> const& b) { 
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    } 
}; 

void func(){
	cin>>n;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
    t = 1;
    while(t--){
        func();
    }
} 