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
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

vector<ll> primes;

void sieve(){
	vector<bool> vis(50001 , false);
	for(int i = 2;i*i < 50001;i++){
		if(vis[i] == false){
			for(int j = i * i;j <= 50000;j += i){
				vis[j] = true;
			}
		}
	}
	for(int i = 2;i < 500001;i++){
		if(vis[i] == false){
			primes.push_back(i);
		}
	}
}


void func(){
	cin>>n;
	ll res = 1;
	for(int i = 0;i < primes.size();i++){
		if(primes[i] <= n){
			p = 0;
			q = n;
			while(q >  0){
				q /= primes[i];
				p += q;
			}
			res = (res * (p + 1)) % mod;
		}
		else{
			break;
		}
	}
	cout<<res<<'\n';

}



int main(){
	sieve();
	cin>>t;
	while(t--){
		func();
	}
} 