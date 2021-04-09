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
	ll a , b , c;
	cin>>n;
	cin>>a>>b>>c;
	string s;
	cin>>s;
	map<char , int> hashmap;
	for(char i : s){
		hashmap[i]++;
	}
	int res = 0;
	string p = "";
	for(char i : s){
		hashmap[i]--;
		if(i == 'S'){
			if(a > 0){
				p += 'R';
				a--;
				res++;
			}
			else{
				if(hashmap['P'] < c){
					p += 'S';
					c--;
				}
				else{
					b--;
					p += 'P';
				}
			}
		}
		else if(i == 'P'){
			if(c > 0){
				p += 'S';
				c--;
				res++;
			}
			else{
				if(hashmap['R'] < b){
					b--;
					p += 'P';
				}
				else{
					a--;
					p += 'R';
				}
			}
		}
		else{
			if(b > 0){
				p += 'P';
				res++;
				b--;
			}
			else{
				if(hashmap['S'] < a){
					a--;
					p += 'R';
				}
				else{
					c--;
					p += 'S';
				}
			}
		}
	}
//	cout<<a<<" "<<b<<" "<<c<<'\n';
	//cout<<p<<'\n';
	if(res >= ceil((double) n / 2)){
		cout<<"YES"<<'\n';
		cout<<p<<'\n';
	}
	else{
		cout<<"NO"<<'\n';
	}
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 