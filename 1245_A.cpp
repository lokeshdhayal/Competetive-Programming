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

ll gcd(ll a , ll b){
	if(b == 0){
		return a;
	}
	return gcd(b , a%b);
}

void func(){
	ll a , b;
	cin>>a>>b;
	ll res = gcd(a , b);
	if(res == 1){
		cout<<"Finite"<<'\n';
	}
	else{
		cout<<"Infinite"<<'\n';
	}
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 