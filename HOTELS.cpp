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

void func(){
	cin>>n>>k;
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	int i = 0;
	int j = 0;
	ll res = 0;
	ll sum_val = 0;
	while(j < a.size() || sum_val >= k){
		if(sum_val == k){
			cout<<sum_val<<'\n';
			return;
		}
		else if(sum_val < k){
			res = max(sum_val , res);
			sum_val += a[j];
			j++;
		}
		else{
			sum_val -= a[i];
			i++;
		}
	}
	cout<<res<<'\n';
}



int main(){
	t = 1;
	while(t--){
		func();
	}
} 