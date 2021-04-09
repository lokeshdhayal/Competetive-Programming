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
	ll C;
	cin>>n>>C;
	vector<pi> p;
	ll sum_val = 0;
	for(int i = 0;i < n;i++){
		ll x , y , c;
		cin>>x>>y>>c;
		sum_val += (y - x + 1)*c;
		p.push_back( { x , c } );
		p.push_back({ y + 1 , -c });
	}
	sort(p.begin() , p.end());
	ll total = 0;
	for(int i = 0;i < 2 * n;i++){
		total += p[i].second;
		if(total > C){
			sum_val -= (total - C) * (p[i + 1].first - p[i].first);
		}
	}
	cout<<sum_val<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 