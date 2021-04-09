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

void func(){
	vi a(n);
	ll sum_val = 0;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		sum_val += a[i];
	}
	if(sum_val%n != 0){
		cout<<-1<<'\n';
		return;
	}
	ll res = 0;
	sum_val /= n;
	for(int i = 0;i < n;i++){
		res += abs(sum_val - a[i]);
	}
	cout<<(res / 2)<<'\n';
}



int main(){
	cin>>n;
	while(n != -1){
		func();
		cin>>n;
	}
} 