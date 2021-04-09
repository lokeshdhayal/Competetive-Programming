#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 998244353
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define ld double
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, temp1 , root , r , p ,q , k;
bool flag = false;

set<int> s;



void find_v(int p){
	if(s.find(p) != s.end()){
	    return;
	}
	s.insert(p);
	if(p > 1000005){
		return;
	}
	find_v(p + 2020);
	find_v(p + 2021);
}


void sieve(){
	find_v(2020);
	find_v(2021);
}

void func(){
	cin>>p;
	if(s.find(p) != s.end()){
		cout<<"YES"<<'\n';
	}
	else{
		cout<<"NO"<<'\n';
	}
}



int main(){
	sieve();
	cin>>t;
    while(t--){
        func();
    }
}