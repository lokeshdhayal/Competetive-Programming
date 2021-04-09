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
	ll a , b;
	cin>>a>>b;
	bool flag =  true;
	if(b == 1){
		b++;
		flag = false;
	}
	ll res = LONG_MAX;
	for(int i = 0;i < 25;i++){
		ll p = i;
		ll q = b + i;
		ll r = a;
		while(r > 0){
			p++;
			r = r / q;
	//		cout<<r<<" "<<p<<'\n';
		}
		res = min(res , p);
	}
	if(flag == false){
		cout<<(res + 1)<<'\n';
		return;
	}
	cout<<res<<'\n';
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
}