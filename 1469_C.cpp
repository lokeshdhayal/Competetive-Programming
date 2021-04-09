#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define F first
#define S second
#define pb(a) push_back(a)
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
typedef vector< pair<ll , ll> > vpi;
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
ll n , t , m , temp , temp2, root , p ,q , k , i , j;


void func(){
	int n;
	cin>>n>>k;
	vi a(n);
	fr(i , n){
		cin>>a[i];
	}
	vpi p(n);
	fr(i , n){
		if(i){
			p[i].F = max(a[i] , p[i - 1].F - k + 1);
			p[i].S = min(a[i] + k - 1 , p[i - 1].S + k - 1);
			if(p[i].F > p[i].S){
				cout<<"NO"<<'\n';
				return;
			}
		}
		else{
			p[i] = { a[i] , a[i] };
		}
	}
	if(p[i - 1].F > a[i - 1]){
		cout<<"NO"<<'\n';
		return;
	}
	cout<<"YES"<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 