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
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , p ,q , k;


void func(){
	ll A , B , C;
	cin>>A>>B>>C;
	ll s = 0;
	ll ss = 0;
	ll mina = LONG_MAX;
	ll minb = LONG_MAX;
	ll minc = LONG_MAX;
	ll min_sum = LONG_MAX;
	for(int i = 0;i < A;i++){
		cin>>temp;
		mina = min(mina , temp);
		s += temp;
		ss += temp;
	}
	min_sum = min(min_sum , ss);
	ss = 0;
	for(int i = 0;i < B;i++){
		cin>>temp;
		minb = min(minb , temp);
		s += temp;
		ss += temp;
	}
	min_sum = min(min_sum , ss);
	ss = 0;
	for(int i = 0;i < C;i++){
		cin>>temp;
		minc = min(minc , temp);
		s += temp;
		ss += temp;
	}
	min_sum = min(min_sum , ss);
	vector<ll> p(3);
	p[0] = mina;
	p[1] = minb;
	p[2] = minc;
	sort(p.begin() , p.end());
	//cout<<min_sum<<" "<<p[0]<<" "<<p[1]<<" "<<p[2]<<'\n';
	ll res = min(min_sum , p[0] + p[1]);
	cout<<(s - 2 * res)<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 