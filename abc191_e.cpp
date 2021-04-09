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
ll n , t , m , temp , temp2, root , r , p ,q , k;
vector<string> a;

int dfs(int  i ,vector< map<int , int> > & adj , vector<int> & vis){
	vis[i] = true;
	int res = 0;
	for(auto j : adj[i]){
		if(vis[j]){
			return ;
		}
		int p = dfs(j , adj , vis);
		if(p != -1){

		}
	}
	vis[i] = false;
	return res;
}


void func(){
	cin>>n>>m;
	vector< map<int , int> > adj[n + 1];
	for(int i = 0;i < m;i++){
		cin>>p>>q>>r;
		if(adj[p].find(q) != adj.end()){
			adj[p][q] = min(adj[p][q] , r);
		}
		else{
			vector<int> b(2);
			b[0] = q;
			b[1] = r;
			adj[p] = b;
		}
	}
	for(int i = 1;i <= n;i++){
		vector<int> vis(n+1 , false);
		cout<<dfs(1 , adj , vis)<<'\n';
	}
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 