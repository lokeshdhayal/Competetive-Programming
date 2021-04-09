#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

ll BIT[300006];

ll find_sum(ll idx){
	ll res = 0;
	while(idx > 0){
		res += BIT[idx];
		idx -= (idx & -idx);
	}
	return res;
}

void update(ll idx){
	while(idx < 300006){
		BIT[idx]++;
		idx += (idx & -idx);
	}
}

void func(){
	cin>>n;
	string s;
	memset(BIT , 0 , sizeof(BIT));
	map<string , int> hashmap;
	for(int i = 2;i <= n + 1;i++){
		cin>>s;
		hashmap[s] = i;
	}
	ll res = 0;
	for(int i = 0;i < n;i++){
		cin>>s;
		res += find_sum(300005) - find_sum(hashmap[s] - 1);
		update(hashmap[s]);
	}
	cout<<res<<'\n';
}



int main(){
	cin>>t;
	while(t--){
		func();
	}
} 