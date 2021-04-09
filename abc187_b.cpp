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


void func(){
	cin>>n;
	vector<pi> a;
	for(int i = 0;i < n;i++){
		cin>>q>>k;
		a.push_back({q , k});
	}
	ll res = 0;
	for(int i = 0;i < n;i++){
		for(int j = i + 1;j < n;j++){
			if(-1 <= (double)(a[i].second - a[j].second)/(a[i].first - a[j].first) && (double)(a[i].second - a[j].second)/(a[i].first - a[j].first) <= 1){
				res++;
			}
		}
	}
	cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 