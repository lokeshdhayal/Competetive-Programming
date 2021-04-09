#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k , res;

vi a;

void dfs(int i , vector<bool> & vis , vi adj[]){
	vis[i] = true;
	res = max(res , a[i - 1]);
	for(auto j : adj[i]){
		if(vis[j] == false){
			dfs(j , vis , adj);
		}
	}
}

void func(){
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	vi adj[n + 1];
	for(int i = 0;i < m;i++){
		cin>>p>>q;
		adj[p].push_back(q);
	}
	ll result = LONG_MIN;
	for(int i = 1;i <= n;i++){
		if(adj[i].size() != 0){
			ll p = a[i - 1];
			res = 0;
			vector<bool> vis(n + 1 , false);
			for(int j : adj[i]){
				dfs(j , vis , adj);
			}
			result = max(result , res - p);
		//	cout<<p<<" "<<res<<'\n';
		}
	}
	cout<<result<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 