#include<iostream>
#include<math.h>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ll long long

ll n,p,q,i,j,rs,count1 = 0,count2 = 0,a[100000],t,temp[400];

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		count1 = 0;
		count2 = 0;
		for(i = 0;i < n;i++){
			cin>>a[i];
		}
		for(i = 0;i < n;i++){
			if(i%2 == 0){
				cout<<a[count1]<<" ";
				count1++;
			}
			else{
				cout<<a[n - 1 - count2]<<" ";
				count2++;
			}
		}
		cout<<"\n";
	}
}