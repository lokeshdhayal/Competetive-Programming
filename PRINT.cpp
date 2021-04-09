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
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res = 3;
int max_val = 0;

vi prime;

void sieve(){
	vb vis(100001 , true);
	for(int i = 2;i*i <= 100000;i++){
		if(vis[i]){
			for(int j = i * i;j <= 100000;j += i){
				vis[j] = false;
			}
		}
	}
	for(int i = 2;i <= 100000;i++){
		if(vis[i]){
			prime.push_back(i);
		}
	}
}

void func(){
	ll l , r;
	cin>>l>>r;
	vb vis(r - l + 1 , true);
	for(int i = 0;(1L)*prime[i] * prime[i] <= r;i++){
		ll base = (l / prime[i]) * prime[i];
	//	cout<<base<<" "<<prime[i]<<'\n';
		if(base < l){
			base = base + prime[i];
		}
		for(int j = base;j <= r;j += prime[i]){
			vis[j - l] = false;
		}
		if(base == prime[i]){
			vis[base - l] = true;
		}
/*		for(int j = 0;j <= r - l;j++){
			if(vis[j]){
				cout<<(j + l)<<' ';
			}
		}
		cout<<"YES"<<base<<" "<<prime[i]<<'\n';*/
	}//l
	for(int i = 0;i <= r - l;i++){
		if(vis[i]){
			cout<<(i + l)<<'\n';
		}
	}
}



int main(){
	cin>>t;
	sieve();
	/*for(int i = 0;i < 10;i++){
		cout<<prime[i]<<" ";
	}*/
    while(t--){
        func();
    }
} 