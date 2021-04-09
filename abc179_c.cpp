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
	cin>>n;
	ll res = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(n - i * j > 0){
				res++;
			}
			else{
				break;
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