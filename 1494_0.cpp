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

bool solve(int A , int B , int C , string s){
	int total = 0;
	for(char i : s){
		if(i == 'A'){
			total += A;
		}
		else if(i == 'B'){
			total += B;
		}
		else{
			total += C;
		}
		if(total < 0){
			return false;
		}
	}
	return total == 0;
}

void func(){
	string s;
	cin>>s;
	if(solve(1 , 1 , -1, s)){
		cout<<"YES"<<'\n';
		return;
	}
	if(solve(1 , -1 , 1,s)){
		cout<<"YES"<<'\n';
		return;
	}
	if(solve(-1 , 1 , 1,s)){
		cout<<"YES"<<'\n';
		return;
	}
	if(solve(1 , -1 , -1,s)){
		cout<<"YES"<<'\n';
		return;
	}
	if(solve(-1 , 1 , -1,s)){
		cout<<"YES"<<'\n';
		return;
	}
	if(solve(-1 , -1 , 1,s)){
		cout<<"YES"<<'\n';
		return;
	}
	cout<<"NO"<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 