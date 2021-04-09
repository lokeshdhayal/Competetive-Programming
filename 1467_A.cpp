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
	cin>>p;
	if(p == 1){
		cout<<9<<'\n';
		return;
	}
	string res = "98";
	p -= 2;
	int q = 9;
	while(p--){
		res += (char)(q + '0');
		if(q == 9){
			q = 0;
		}
		else{
			q++;
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