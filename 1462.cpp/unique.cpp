#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long
ll p,q,n,a[30005],minimum,max1,i,j,temp,x,t;


int main(){
	cin>>t;
	while(t--){
		cin>>n;
		string s;
		s = "";
		if(n>45){
			cout<<-1;
		}
		else{
			for(i = 9;i >= 1;i--){
				if(i <= n){
					s += i + '0';
					n -= i;
				}
			}
			for(i = s.size() - 1;i >= 0;i--){
				cout<<s[i];
			}
		}
		cout<<"\n";
	}
}