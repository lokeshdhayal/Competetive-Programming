#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long

ll n,p,q,i,j,rs,count1 = 0,count2 = 0,a[100000],t,temp[400],result;
int dp[200][5];

int main(){
	cin>>t;
	string s2;
	s2 = "2020";
	while(t--){
		cin>>n;
		if(n/10 == 0){
			cout<<n;
		}
		else{
			result = n/10 + n%10;
			if(result%10 != result/10){
				cout<<result;
			}
			else{
				cout<<-1;
			}
		}
		cout<<"\n";
	}
}