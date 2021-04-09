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

void func(){
	ll d;
	cin>>n>>d;
	vi a;
	input(a , n);
	for(int i = 0;i < n;i++){
		bool flag = false;
		if(a[i] >= d*10){
			flag = true;
		}
		if(flag == false){
			while(a[i] >= d){
				a[i] -= d;
				if(a[i]%10 == 0){
					flag = true;
					break;
				}
			}
		}
		if(flag){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 