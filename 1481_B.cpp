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
	cin>>n>>k;
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	ll p = 0;
	while(k > 0){
		bool flag = false;
		for(int i = 0;i < n - 1;i++){
			if(a[i] < a[i + 1]){
				a[i]++;
				p = i + 1;
				k--;
				flag = true;
				break;
			}
		}
		if(flag == false){
			cout<<-1<<'\n';
			return;
		}
	}
	cout<<p<<'\n';
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
}