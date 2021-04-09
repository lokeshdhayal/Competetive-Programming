#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000000

typedef vector<int> vi;


ll t , w2 , w1 , w , n;

void func(){
	cin>>w2>>w1;
	w = w1 - w2;
	cin>>n;
	vi wt(n);
	vi p(n);
	for(int i = 0;i < n;i++){
		cin>>p[i]>>wt[i];
	}
	vector<int> dp(w + 1 , INT_MAX);
	dp[0] = 0;
	for(int i = 0;i < n;i++){
		for(int j = 1;j <= w;j++){
			if(j >= wt[i] && dp[j - wt[i]] != INT_MAX){
				dp[j] = min(dp[j - wt[i]] + p[i], dp[j]);
			}
		}
	}
	if(dp[w] == INT_MAX){
		cout<<"This is impossible."<<'\n';
	}
	else{
		cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<'.'<<'\n';
	}
}

int main(){
	cin>>t;
	while(t--){
		func();
	}
}
