#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k , res;

void func(){
	cin>>n;
	vi v(n);
	for(int i = 0;i < n;i++){
		cin>>v[i];
	}
	int p = v[0];
	ll res = 0;
	int i = 1;
	while(i < n){
		if(v[i] > p){
			p = v[i];
		}
		else{
			res += p - v[i];
		}
		i++;
	}
	cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 