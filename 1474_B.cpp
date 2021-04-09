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

ll next_p(ll a){
	while(true){
		bool flag = false;
		for(int i = 2;i * i <= a;i++){
			if(a % i == 0){
				flag = true;
				break;
			}
		}
		if(flag){
			a++;
		}
		else{
			break;
		}
	}
	return a;
}


void func(){
	cin>>p;
	ll a = 1 + p;
	a = next_p(a);
	ll b = a + p;
	b = next_p(b);
	cout<<(a * b)<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 