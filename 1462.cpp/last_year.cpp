#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long
ll p,q,n,a[30005],minimum,max1,i,j,temp,x,t;

void func(){
	cin>>n;
	string s;
	cin>>s;
	for(i = 0;i <= 4;i++){
		string t1 = s.substr(0,i);
		string t2 = s.substr(n-4+i);
		string ans = t1 + t2;
		if(ans == "2020"){
			cout<<"YES"<<"\n";
			return;
		}
	}
	cout<<"NO";
	cout<<"\n";
}

int main(){
	cin>>t;
	while(t--){
		func();
	}
}