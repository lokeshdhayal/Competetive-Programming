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



void func(){
	cin>>n;
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	ll res = 0;
	vector<ll> dp(n , 0);
	for(int i = 0;i < n;i++){
		dp[i] += a[i];
		if(a[i] + i < n){
			dp[i + a[i]] = max(dp[i] , dp[i + a[i]]);
		}
		res = max(dp[i] , res);
	}
	cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 