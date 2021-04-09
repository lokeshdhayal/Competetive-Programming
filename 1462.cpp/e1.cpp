#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long
ll p,q,n,a[30005],minimum,max1,i,j,temp,x,t;

ll max_value(ll a,ll b,ll c){
	if(a > b && a > c){
		return a;
	}
	else if(b > a && b > c){
		return b;
	}
	else{
		return c;
	}
}

ll min_value(ll a,ll b,ll c){
	if(a < b && a < c){
		return a;
	}
	else if(b < a && b < c){
		return b;
	}
	else{
		return c;
	}
}

void func(){
	cin>>n;
	ll count1 = 0;
	for(i = 0;i < n;i++)cin>>a[i];
	for(i = 0;i < n;i++){
		for(j = i+1;j < n;j++){
			for(ll k = j+1;k < n;k++){
				if((max_value(a[i],a[j],a[k]) - min_value(a[i],a[j],a[k])) <= 2){
					count1++;
					cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
				}
			}
		}
	}
	cout<<count1<<"\n";
}

int main(){
	cin>>t;
	while(t--){
		func();
	}
}