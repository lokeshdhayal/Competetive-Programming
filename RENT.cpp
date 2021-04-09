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
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res = 3;
int max_val = 0;

bool comp(vi a , vi b){
	return a[0] < b[0];
}
void func(){
	cin>>n;
	vi dp(n + 1 , 0);
	vector<vi> a;
	for(int i = 0;i < n;i++){
		cin>>p>>q>>r;
		vi b(3);
		b[0] = p;
		b[1] = q;
		b[2] = r;
		a.push_back(b);
	}
	sort(a.begin() , a.end() , comp);
	ll res = 0;
	for(int i = 0;i < a.size();i++){
		dp[i + 1] = a[i][2];
		for(int j = 0;j < i;j++){
			if(a[i][0] > a[j][0] + a[j][1]){
				dp[i + 1] = max(dp[i + 1] , dp[j + 1] + a[i][2]);
			}
		}
		res = max(res , dp[i + 1]);
	}
	cout<<res<<'\n';
}



int main(){
	cin>>t;
    while(t--){
        func();
    }
} 