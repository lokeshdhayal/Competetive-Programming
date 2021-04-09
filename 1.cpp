#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long

ll n,p,q,i,j,rs,count1 = 0,count2 = 0,a[100000],t,temp[400];
int dp[200][5];

int main(){
	cin>>t;
	string s2;
	s2 = "2020";
	while(t--){
		cin>>n;
		string s1;
		cin>>s1;
		for(i = 0;i < n;i++){
			for(j = 0;j < 4;j++){
				if(i == 0 || j == 0){
					dp[i][j] = 0;
				}
			}
		}
		for(i = 1;i <= n;i++){
			for(j = 1;j <= 4;j++){
				if(s1[i] == s2[j]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else{
					if(dp[i-1][j] > dp[i][j-1]){
						dp[i][j] = dp[i-1][j];
					}
					else{
						dp[i][j] = dp[i][j-1];
					}
				}
			}
		}
		if(dp[n][4] == 4){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
}