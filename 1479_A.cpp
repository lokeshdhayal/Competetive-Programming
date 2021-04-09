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

ll ask(int p){
	cout<<"? "<<p<<'\n';
	ll x;
	cin>>x;
	return x;
}


void func(){
	//cout<<"yes";
	cin>>n;
	if(n == 1){
		cout<<"! "<<1<<'\n';
		return;
	}
//	cout<<"yes";
	ll l = 1;
	ll r = n;
	while(l <= r){
		ll mid = (r - l) / 2 + l;
		ll mid_el = ask(mid);
		if(mid == 1){
			ll mid_next = ask(mid + 1);
			if(mid_next > mid_el){
				cout<<"! "<<mid<<'\n';
				return;
			}
			else{
				l = mid + 1;
			}
		}
		else if(mid == n){
			ll mid_prev = ask(mid - 1);
			if(mid_prev > mid_el){
				cout<<"! "<<mid<<'\n';
				return;
			}
			else{
				r = mid - 1;
			}
		}
		else{
			ll mid_prev = ask(mid - 1);
			ll mid_next = ask(mid + 1);
			if(mid_prev > mid_el && mid_el < mid_next){
				cout<<"! "<<mid<<'\n';
				return;
			}
			if(mid_prev < mid_next){
				r = mid - 1;
			}
			else{
				l = mid + 1;
			}
		}
	}
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 