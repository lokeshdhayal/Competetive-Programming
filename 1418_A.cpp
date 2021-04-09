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
	cin>>p>>q>>r;
	
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 