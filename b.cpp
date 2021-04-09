#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long

ll n,p,q,i,j,rs,count1 = 0,count2 = 0,t,temp[400],result, k = -1;
int dp[200][5];

int main(){
	cin>>t;
	string a;
	a = "2020";
	while(t--){
		cin>>n;
		int flag;
		string s;
		cin>>s;
		flag = 0;
		for(i = 0;i < 2;i++){
			flag = 1;
			k = 0;
			for(j = 0;j < i;j++){
				k++;
				if(a[k] != s[j]){
					cout<<a[k]<<" "<<s[k]<<"\n";
					flag = 0;
					break;
				}
			}
			if(flag == 1){
				for(j = n-i-1;j < n;j++){
					k++;
					if(a[k] != s[i]){
						flag = 0;
						break;
					}
				}
			}
			if(flag == 1){
				break;
			}
		}
		if(flag == 1){
			cout<<"YES"<<"\n";
		}
		else{
			cout<<"NO"<<"\n";
		}
	}
}