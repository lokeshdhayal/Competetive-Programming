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
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res = 3;
int max_val = 0;

map<pi , int> hashmap;


int find_v(int open , int close , set<int> & s ,int pos){
	if(close > open){
		return 0;
	}
	if(hashmap.find({open , close }) != hashmap.end()){
		return hashmap[{open , close}];
	}
	if(open + close == 2*n && open == close){
		return hashmap[{open , close}] = 1;
	}
	if(open + close == 2 * n){
		return hashmap[{open , close}] = 0;
	}
	if(s.find(pos) != s.end()){
		return hashmap[{open , close}] = find_v(open + 1 , close , s , pos + 1);
	}
	else{
		return hashmap[{open , close}] = find_v(open + 1 , close , s , pos + 1) + find_v(open , close + 1 , s , pos + 1);
	}
}



void func(){
	hashmap.clear();
	cin>>n>>k;
	set<int> s;
	for(int i = 0;i < k;i++){
		cin>>temp;
		s.insert(temp);
	}
	cout<<find_v(0 , 0 , s , 1)<<'\n';
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
} 