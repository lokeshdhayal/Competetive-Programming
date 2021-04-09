#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res = 3;
int max_val = 0;

bool comp(vi a, vi b){
	return a[0]*b[1] < b[0] * a[1];
}

int gcd(int a , int b){
	if(b == 0){
		return a;
	}
	return gcd(b , a % b);
}

void func(){
	cin>>n>>m;
	vector<vi> dp;
	vi lok(2);
	lok[0] = 0;
	lok[1] = 1;
	dp.push_back(lok);
	vi q(2);
	q[0] = 1;
	q[1] = n;
	dp.push_back(q);
	double x1 = 0 , y1 = 1 , x2 = 1 , y2 = n;
	double x = 0,y = 0;
	while(y != 1.0){
		x = floor((y1 + n) / y2) * x2 - x1;
		y = floor((y1 + n) / y2) * y2 - y1;
		vi a(2);
		a[0] = (int)x;
		a[1] = (int)y;
		dp.push_back(a);
		x1 = x2;
		x2 = x;
		y1 = y2;
		y2 = y;
	}
	while(m--){
		cin>>p;
		cout<<dp[p - 1][0]<<"/"<<dp[p - 1][1]<<'\n';
	}
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
} 