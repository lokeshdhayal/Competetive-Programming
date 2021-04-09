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
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , p ,q , k;

char a[3][3];

bool is_valid(char p){
	if(a[0][0] == p && a[0][1] == p && a[0][2] == p){
		return true;
	}
	if(a[1][0] == p && a[1][1] == p && a[1][2] == p){
		return true;
	}
	if(a[2][0] == p && a[2][1] == p && a[2][2] == p){
		return true;
	}
	if(a[0][0] == p && a[1][0] == p && a[2][0] == p){
		return true;
	}
	if(a[0][1] == p && a[1][1] == p && a[2][1] == p){
		return true;
	}
	if(a[0][2] == p && a[1][2] == p && a[2][2] == p){
		return true;
	}
	if(a[0][0] == p && a[1][1] == p && a[2][2] == p){
		return true;
	}
	if(a[2][0] == p && a[1][1] == p && a[0][2] == p){
		return true;
	}
	return false;
}


void func(){
	ll count_X = 0;
	ll count_O = 0;
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin>>a[i][j];
			if(a[i][j] == 'O'){
				count_O++;
			}
			else if(a[i][j] == 'X'){
				count_X++;
			}
		}
	}
	if(count_O > count_X){
		cout<<"no"<<'\n';
		return;
	}
	if(abs(count_O - count_X) > 1){
		cout<<"no"<<'\n';
		return;
	}
	if(count_X + count_O == 9){
		cout<<"yes"<<'\n';
		return;
	}
	if(count_O == count_X){
		if(is_valid('X')){
			cout<<"noerf"<<'\n';
			return;
		}
		else{
			cout<<"yes"<<'\n';
			return;
		}
	}
	if(is_valid('O')){
		cout<<"no"<<'\n';
		return;
	}

	cout<<"yes"<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 