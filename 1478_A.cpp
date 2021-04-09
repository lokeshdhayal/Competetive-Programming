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

void input(vi & a , int n){
	for(int i = 0;i < n;i++){
		cin>>temp;
		a.push_back(temp);
	}
}

void func(){
	cin>>n;
	vi a;
	map<int , int> hashmap;
	input(a , n);
	int res = 0;
	for(int i = 0;i < n;i++){
		hashmap[a[i]]++;
		res = max(res , hashmap[a[i]]);
	}
	cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 