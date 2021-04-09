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

int res = 3;
int max_val = 0;


void find_left(vi & a , int i){
	if(i >= a.size()){
		return;
	}
	if(a[i] > max_val){
		res = p;
		max_val = a[i];
	}
	find_left(a , 2*i);
	find_left(a , 2*i + 1);
}

void func(){
	cin>>n;
	ll p = 1 << n;
	vector<pi> a;
	//cout<<p<<'\n';
	for(int i = 0;i < p;i++){
		cin>>temp;
		a.push_back({temp , i + 1});
	}
	while(a.size() > 2){
		vector<pi> b;
		for(int i = 0;i < a.size();i += 2){
			if(a[i].first > a[i + 1].first){
				b.push_back(a[i]);
			}
			else{
				b.push_back(a[i + 1]);
			}
		}
		a = b;
	}
	if(a[0].first > a[1].first){
		cout<<a[1].second<<'\n';
	}
	else{
		cout<<a[0].second<<'\n';
	}
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 