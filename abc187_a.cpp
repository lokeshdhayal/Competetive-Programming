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
	cin>>p>>q;
	int temp1 = p%10;
	p /= 10;
	temp1 += p%10;
	p /= 10;
	temp1 += p;
	int temp2 = q%10;
	q /= 10;
	temp2 += q%10;
	q /= 10;
	temp2 += q;
	cout<<max(temp1 , temp2)<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 