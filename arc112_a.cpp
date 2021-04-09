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

int find_v(int i , int j , int l){
	int r = l - i;
	if(r < i){
		return 0;
	}
	if(r >= p && r <= q){
		return r - p;
	}
	else{
		return q - r;
	}
}

void func(){
	cin>>p>>q;
	ll res = 0;
	for(int i = p;i <= q;i++){
		if(i + p <= q){
			int lok = find_v(p , q , i);
			res += lok;
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