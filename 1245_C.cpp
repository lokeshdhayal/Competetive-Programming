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

int res = 3;
int max_val = 0;

ll gcd(ll a , ll b){
	if(b == 0){
		return a;
	}
	return gcd(b , a%b);
}

void func(){
	string s;
	cin>>s;
	vi dp(s.size() + 1 , 1);
	for(int i = 0;i < s.size();i++){
		if(s[i] == 'w' || s[i] == 'm'){
			cout<<0<<"\n";
			return;
		}
		if(i > 0 && s[i] == 'n' && s[i - 1] == 'n'){
			dp[i + 1] = (dp[i - 1] + dp[i])%mod;
		}
		else if(i > 0 && s[i] == 'u' && s[i - 1] == 'u'){
			dp[i + 1] = (dp[i - 1] + dp[i])%mod;
		}
		else{
			dp[i + 1] = dp[i];
		}
	}
	cout<<dp[s.size()]<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 