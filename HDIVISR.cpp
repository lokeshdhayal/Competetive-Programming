#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m;


void func(){
	cin>>n;
	for(int i = 10;i >= 1;i--){
		if(n%i == 0){
			cout<<i<<nl;
			return;
		}
	}
}

int main(){
    t = 1;
    while(t--){
        func();
    }
} 