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
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res;


void func(){
	cin>>m>>n;
	vi a(m);
	vi b(n);
	res = 0;
	ll sum_val1 = 0;
	ll sum_val2 = 0;
	for(int i = 0;i < m - 1;i++){
		cin>>a[i];
		sum_val1 += a[i];
	}
	for(int i = 0;i < n - 1;i++){
		cin>>b[i];
		sum_val2 += b[i];
	}
	ll res = 0;
	sort(a.begin() , a.end() , greater<int>());
	sort(b.begin() , b.end() , greater<int>());
	int i = 0;
	int j = 0;
	while(i < a.size() && j < b.size()){
		if(a[i] == b[j]){
			if(sum_val1 > sum_val2){
				res += b[j];
				res += sum_val1;
				sum_val2 -= b[j];
				j++;
			}
			else{
				res += a[i];
				res += sum_val2;
				sum_val1 -= a[i];
				i++;
			}
		}
		else if(a[i] > b[j]){
			res += a[i];
			res += sum_val2;
			sum_val1 -= a[i];
			i++;
		}
		else{
			res += b[j];
			res += sum_val1;
			sum_val2 -= b[j];
			j++;
		}
	}
	while(i < a.size()){
		res += a[i];
		i++;
	}
	while(j < b.size()){
		res += b[j];
		j++;
	}
	cout<<res<<'\n';
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
}