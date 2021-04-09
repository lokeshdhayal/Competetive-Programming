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
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	ll res = 0;
	ll ans = -1;
	for(int i = 2;i < 1000;i++){
		ll p = 0;
		for(int j = 0;j < n;j++){
			if(a[j]%i == 0){
				p++;
			}
		}
		if(p >= res){
			ans = i;
			res = p;
		}
	}
	cout<<ans<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 