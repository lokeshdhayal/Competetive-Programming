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
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , p ,q , k;


void func(){
	string s;
	cin>>s;
	int i = 1;
	ll res = 0;
	while(i < s.size()){
		if(s[i] == s[i - 1]){
			s[i] = '*';
		}
		if(i > 1 && s[i] == s[i - 2]){
			s[i] = '*';
		}
		if(s[i] == '*'){
			res++;
		}
		i++;
	} 

	cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 