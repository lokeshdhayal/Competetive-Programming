#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;


/*int solve(string & s){
	int n = (int)s.size();
	vector<int> dp(n + 1 , 0);
	dp[0] = 1;
	for(int i = 1;i <= n;i++){
		if(s[i-1] != '0')dp[i] = dp[i - 1];
		if(i != 1 && s[i - 2] != '0'){
			if((s[i - 2] - '0')*10 + s[i - 1] - '0' <= 26){
				dp[i] += dp[i - 2];
			}
		}
	}
	return dp[n];
}*/


int dp[100][27];
int solve(string & s , int i , int val){
	if(val > 26 || val == 0){
		return 0;
	}
	int & ans = dp[i][val];
	if(ans != -1){
		return ans;
	}
	if(i == (int)s.size()){
		return 1;
	}
	int res = 0;
	res += solve(s,i+1,s[i] - '0');
	if(i != (int)s.size() - 1 && s[i] != '0'){
		res += solve(s,i+2,(s[i]-'0')*10 + s[i+1]-'0');
	}
	return ans = res;
}



int main(){
	string s;
	cin>>s;
	for(int i = 0;i < 100;i++){
		for(int j = 0;j < 27;j++){
			dp[i][j] = -1;
		}
	}
	cout<<solve(s,0,1)<<'\n';
}