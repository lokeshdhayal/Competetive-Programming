#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define ld double
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res = 3;
int max_val = 0;



void func(){
	cin>>n;
	vector<vi> dp(n , vi(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			cin>>dp[i][j];
		}
	}
	vector<pi> res;
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			int dis = dp[i - 1][j - 1];
			bool flag = true;
			for(int k = 1;k <= n;k++){
				if(k == i || k == j){
					continue;
				}
				p = dp[k - 1][i - 1] + dp[k - 1][j - 1];
				if(p == dis){
					flag = false;
					break;
				}
			}
			if(flag){
				res.push_back({ i , j });
			}
		}
	}

	for(int i = 0;i < res.size();i++){
		cout<<res[i].first<<" "<<res[i].second<<'\n';
	}

}



int main(){
	cin>>t;
    while(t--){
        func();
    }
}