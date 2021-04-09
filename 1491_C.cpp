#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
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


void func(){
	string s;
	cin>>s;
	if(s[s.size() - 1] == 's'){
		s += 'e';
		s += 's';
	}
	else{
		s += 's';
	}
	cout<<s;
}



int main(){
	t = 1;
    while(t--){
        func();
    }
}