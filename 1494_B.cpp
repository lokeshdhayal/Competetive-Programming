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
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k , res;

void func(){
	cin>>n;
	vi p;
	for(int i = 0;i < 4;i++){
		cin>>temp;
		p.push_back(temp);
	}
	if(p[0] == n){
		if(p[2] == n){
			if(p[1] < 2 || p[3] < 2){
			//	cout<<"1"<<'\n';
				cout<<"NO"<<'\n';
				return;
			}
		}
		if(p[2] == n - 1){
			if(p[1] < 2 && p[3] < 2){
			//	cout<<"2"<<'\n';
				cout<<"NO"<<'\n';
				return;
			}

		}
	}
	if(p[1] == n){
		if(p[3] == n){
			if(p[2] < 2 || p[0] < 2){
				cout<<"NO"<<'\n';
			//	cout<<"3"<<'\n';
				return;
			}
		}
		if(p[3] == n - 1){
			if(p[2] < 2 && p[0] < 2){
				cout<<"NO"<<'\n';
			//	cout<<"4"<<'\n';
				return;
			}
		}
	}
	
	if(p[2] == n){
		if(p[0] == n){
			if(p[1] < 2 || p[3] < 2){
				cout<<"NO"<<'\n';
			//	cout<<"5"<<'\n';
				return;
			}
		}
		if(p[0] == n - 1){
			if(p[1] < 2 && p[3] < 2){
				cout<<"NO"<<'\n';
			//	cout<<"6"<<'\n';
				return;
			}
		}
	}
	if(p[3] == n){
		if(p[1] == n){
			if(p[0] < 2 || p[2] < 2){
				cout<<"NO"<<'\n';
			//	cout<<"7"<<'\n';
				return;
			}
		}
		if(p[1] == n - 1){
			if(p[0] < 2 && p[2] < 2){
				cout<<"NO"<<'\n';
				//cout<<"8"<<'\n';
				return;
			}
		}
	}
	if(p[0] == n - 1 && p[1] == 0 && p[3] == 0){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[1] == n - 1 && p[2] == 0 && p[0] == 0){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[2] == n - 1 && p[3] == 0 && p[1] == 0){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[3] == n - 1 && p[2] == 0 && p[0] == 0){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[0] == n - 1 && p[2] == n - 1){
		if(p[1] == 0 && p[3] < 2){
			cout<<"NO"<<'\n';
			//cout<<"8"<<'\m'
			return;
		}
		if(p[3] == 0 && p[1] < 2){
			cout<<"NO"<<'\n';
			//cout<<"8"<<'\m'
			return;
		}
	}
	if(p[1] == n - 1 && p[3] == n - 1){
		if(p[2] == 0 && p[0] < 2){
			cout<<"NO"<<'\n';
			return;
		}
		if(p[0] == 0 && p[2] < 2){
			cout<<"NO"<<'\n';
			return;
		}
	}
	if(p[0] == n && (p[1] == 0 || p[3] == 0)){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[1] == n && (p[0] == 0 || p[2] == 0)){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[2] == n && (p[1] == 0 || p[3] == 0)){
		cout<<"NO"<<'\n';
		return;
	}
	if(p[3] == n && (p[2] == 0 || p[0] == 0)){
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