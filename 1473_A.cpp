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
	vi a(n);
	int min1 = INT_MAX;
	int min2 = INT_MAX;
	bool flag = false;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] > k){
			flag = true;
		}
		if(min1 > a[i]){
			min2 = min1;
			min1 = a[i];
		}
		else if(a[i] < min2){
			min2 = a[i];
		}
	}
//	cout<<min1<<" "<<min2<<" "<<flag<<'\n';
	if(flag){
		if(min1 + min2 <= k){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
	else{
		cout<<"YES"<<'\n';
	}
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 