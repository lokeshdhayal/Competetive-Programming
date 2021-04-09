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



void func(){
	cin>>n>>k;
	ll res = (n - k) * (n - k );
	vi a(k);
	int i = 1;
	int j = k;
	p = 0;
	while(p < k){
		if(res >= j - i){
			a[p] = j;
			res -= j - i;
			j--;
		}
		else{
			a[p] = i;
			i++;
		}
		p++;
	}
	for(int i = 0;i < k;i++){
		cout<<a[i]<<" ";
	}
	cout<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 