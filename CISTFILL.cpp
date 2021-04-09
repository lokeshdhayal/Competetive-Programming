#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define ld double
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

int res = 3;
int max_val = 0;

bool check(vector<vi> a ,double mid, double V){
	double res = 0;
	for(int i = 0;i < a.size();i++){
		double area = a[i][2] *a[i][3];
		double height;
		if(mid <= a[i][0]){
			height = 0;
		}
		else if(mid >= a[i][0] + a[i][1]){
			height = a[i][1];
		}
		else{
			height = mid - a[i][0];
		}
		res += height * area;
	}
	return (res >= V);
}



void func(){
	cin>>n;
	vector<vi> a;
	ll res = 0;
	for(int i = 0;i < n;i++){
		cin>>p>>q>>r>>k;
		vi b(4);
		b[0] = p;
		b[1] = q;
		b[2] = r;
		b[3] = k;
		a.push_back(b);
		res = max(res , p + q);
	}
	double V;
	cin>>V;
	double l = 0;
	double r = res;
	//cout<<check(a , 1 , 1)<<'\n';
	if(check(a  , r , V) == false){
		cout<<"OVERFLOW"<<'\n';
		return;
	}
	double result = r;
	while(r - l > 0.000001){
		double mid = (r - l) / 2 + l;
		if(check(a , mid , V)){
			r = mid;
			result = min(result , mid);
		}
		else{
			l = mid;
		}
	}
	printf("%0.2f\n",result);
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
#endif
	cin>>t;
    while(t--){
        func();
    }
#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
} 