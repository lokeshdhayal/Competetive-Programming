#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k , res;

void func(){
	cin>>n>>m;
	vi q(m);
	vi p(n);
	for(int i = 0;i < n;i++){
		cin>>p[i];
	}
	for(int i = 0;i < m;i++){
		cin>>q[i];
	}
	int i = 0;
	int j = 0;
	vi result(m);
	int res = 0;
	while(i < n && j < m){
		if(a[i] == a[j]){
			res++;
			result[j] = res;
			i++;
			j++;
		}
		else if(a[i] > a[j]){
			j++;
			result[j] = res;
		}
		else{
			i++;
		}
	}
	while(j < m){
		result[j] = res;
		j++;
	}


}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 