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

bool check(ll p ,vi & a,int mid){
	for(int i = 0;i < a.size();i++){
		double q = sqrt((double)((double)mid * 2) / a[i]  + 0.25) - 0.5;
	//	cout<<a[i]<<" "<<q<<" "<<((double)((double)mid * 2) / a[i])<<'\n';
		p -= floor(q);
	}
	return (p <= 0);
}

void func(){
	cin>>p>>q;
	if(p < q){
		swap(p , q);
	}
	if(p < q + 3){
		cout<<"Yes"<<'\n';
	}
	else{
		cout<<"No"<<'\n';
	}
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 