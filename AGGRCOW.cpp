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

void input(vi & a , int n){
	for(int i = 0;i < n;i++){
		cin>>temp;
		a[i] = temp;
	}
}

bool check(ll p ,vi & a,int l){
	ll j = a[0];
	l--;
	for(int i = 1;i < a.size();i++){
		if(a[i] >= j + p){
			j = a[i];
			l--;
		}
	}
	return (l <= 0);
}

void func(){
	cin>>n>>k;
	vi a(n);
	input(a , n);
	sort(a.begin() , a.end());
	ll l = 1;
	ll res = 0;
	ll r = 1000000000;
	while(l <= r){
		ll mid = (r - l) / 2 + l;
		if(check(mid , a , k)){
			res = max(mid , res);
			l = mid + 1;
		}
		else{
			r = mid - 1;
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