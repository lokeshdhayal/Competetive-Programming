#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000000

ll m , n , t;

void func(){
	cin>>m>>n;
	char a[m][n];
	vector<vector<int> > dp1(m + 1 , vector<int>(n + 1 , INF));
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, INF));
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cin>>a[i][j];
		}
	}
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			if(a[i][j] == '1'){
				dp1[i+1][j+1] = 0;
			}
			else{
				dp1[i + 1][j + 1] = min(dp1[i][j + 1] , dp1[i + 1][j]) + 1;
			}
		}
	}
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			dp[i][j] = dp1[i + 1][j + 1];
		}
	}
	for(int i = m - 1;i >= 0;i--){
		for(int j = n - 1;j >= 0;j--){
			dp[i][j] = min(min(dp[i + 1][j] + 1 , dp[i][j + 1] + 1) , dp[i][j]);
		}
	}
	for(int i = 0;i < m;i++){
		for(int j = 0;j < n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<nl;
	}
}

int main(){
	cin>>t;
	while(t--){
		func();
	}
}
