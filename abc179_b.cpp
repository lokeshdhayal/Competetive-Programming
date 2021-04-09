#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
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
	cin>>n;
	vector<pi> a;
	for(int i = 0;i < n;i++){
		cin>>p>>q;
		a.push_back({p , q});
	}
	bool flag = false;
	for(int i = 0;i < n - 2;i++){
		if(a[i].first == a[i].second && a[i + 1].first == a[i + 1].second && a[i + 2].first == a[i + 2].second){
			flag = true;
		}
	}
	if(flag){
		cout<<"Yes"<<'\n';
	}
	else{
		cout<<"No"<<'\n';
	}
}



int main(){
	t = 1;
    while(t--){
        func();
    }
}