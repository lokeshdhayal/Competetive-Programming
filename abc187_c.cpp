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
	cin>>n;
	set<string> s1;
	vector<string> s2;
	while(n--){
		string s;
		cin>>s;
		if(s[0] == '!'){
			s2.push_back(s);
		}
		else{
			s1.insert(s);
		}
	}
	for(int i = 0;i < s2.size();i++){
		if(s1.find(s2[i].substr(1)) != s1.end()){
			cout<<s2[i].substr(1)<<'\n';
			return;
		}
	}
	cout<<"satisfiable"<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 