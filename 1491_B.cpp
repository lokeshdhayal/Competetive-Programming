#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define ld double
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, temp1 , root , r , p ,q , k;


void func(){
	cin>>n>>p>>q;
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	bool flag = true;
	temp = a[0];
	for(int i = 1;i < n;i++){
		if(temp != a[i]){
			flag = false;
			break;
		}
	}
	bool flag2 = false;
	for(int i = 0;i < n - 1;i++){
		if(abs(a[i] - a[i + 1]) >= 2){
			flag2 = true;
			break;
		}
	}
	if(flag2){
		cout<<0<<'\n';
		return;
	}
	if(flag){
		cout<<(p + q)<<'\n';
	}
	else{
		cout<<min(p , q)<<'\n';
	}
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
}