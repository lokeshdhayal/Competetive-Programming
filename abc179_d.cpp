#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 998244353
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define ld double
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, temp1 , root , r , p ,q , k;


void func(){
	cin>>temp>>n;
	vector<pi> a;
	for(int i = 0;i < n;i++){
		cin>>p>>q;
		a.push_back({ p , q });
	}
	vector<ll> dp(temp, 0);
	dp[0] = 1;
	sort(a.begin() , a.end());
	for(int i = 1;i < temp;i++){
		if(i > 0){
			dp[i] = (dp[i] + dp[i - 1])%mod;
		}
		for(int j = 0;j < n;j++){
			if(i + a[j].first < temp){
				cout<<"yes"<<'\n';
				dp[i + a[j].first] = (dp[i] + dp[i + a[j].first])%mod;
			}
			if(i + a[j].second < temp){
				dp[i + a[j].second] -= dp[i];
			}
		}
		for(int i = 0;i < temp;i++){
		cout<<dp[i]<<" ";
	}
	cout<<'\n';
	}
	cout<<(dp[temp - 1]%mod)<<'\n';
}



int main(){
	t = 1;
    while(t--){
        func();
    }
}