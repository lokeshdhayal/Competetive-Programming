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
	vi a(n);
	vi b(n);
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	for(int i = 0;i < n;i++){
		cin>>b[i];
	}
	int res_val = 0;
	for(int i = 0;i < n;i++){
		res_val += a[i] * b[i];
	}
	if(res_val == 0){
		cout<<"Yes"<<'\n';
	}
	else{
		cout<<"No"<<'\n';
	}
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 