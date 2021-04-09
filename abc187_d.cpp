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

bool comp(pi a , pi b){
	return (a.first > b.first) || (a.first == b.first  &&  a.second > b.second);
}


void func(){
	cin>>n;
	vector<ll> a;
	ll res1 = 0;
	ll res2 = 0;
	for(int i = 0;i < n;i++){
		cin>>p>>q;
		res1 -= p;
		a.push_back(p + p + q);
	}
	sort(a.begin() , a.end());
	ll res = 0;
	while(res1 <= 0){
		res++;
		res1 += a.back();
		a.pop_back();
	}
	cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 