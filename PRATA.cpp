#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;
vector<string> a;

bool check(ll p ,vi & a,int mid){
	for(int i = 0;i < a.size();i++){
		double q = sqrt((double)((double)mid * 2) / a[i]  + 0.25) - 0.5;
	//	cout<<a[i]<<" "<<q<<" "<<((double)((double)mid * 2) / a[i])<<'\n';
		p -= floor(q);
	}
	return (p <= 0);
}

void func(){
	cin>>k>>n;
	ll max_val = 0;
	vi a(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
		max_val = max(max_val , a[i]);
	}
	ll l = 0;
	r = max_val * (k) * (k + 1) / 2;
	ll res = r;
	//cout<<check(k , a , 11)<<" "<<"yes"<<'\n';
	while(l <= r){
		ll mid = (r - l) / 2 + l;
	//	cout<<l<<" "<<r<<" "<<mid<<'\n';
		if(check(k , a , mid)){
			r = mid - 1;
			res = min(mid , res);
		}
		else{
			l = mid + 1;
		}
	}
	cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 