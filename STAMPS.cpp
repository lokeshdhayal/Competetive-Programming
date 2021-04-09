#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

void func(){
	cout<<"Scenario #"<<p<<':'<<'\n';
	cin>>k>>n;
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a.begin() , a.end() , greater<ll>());
	int res = 0;
	for(int i = 0;i < a.size();i++){
		k -= a[i];
		res++;
		if(k <= 0){
			break;
		}
	}
	if(k > 0){
		cout<<"impossible"<<"\n\n";
		return;
	}
	cout<<res<<"\n\n";
}



int main(){
	cin>>t;
	while(t--){
		p++;
		func();
	}
} 