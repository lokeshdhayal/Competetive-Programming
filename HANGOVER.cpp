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
ll t , m , temp , temp2, root , r , p ,q , k;
double n;

void func(){
	ll i = 2;
	int j = 0;
	double lok = n;
	while(lok > 0){
		j++;
		lok -= 1.0 / i;
		i++;
	}
	cout<<j<<" card(s)"<<'\n';
}



int main(){
	cin>>n;
	while(n != 0){
		func();
		cin>>n;
	}
} 