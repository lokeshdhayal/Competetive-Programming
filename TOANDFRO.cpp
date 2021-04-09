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

map<char , int> hashmap1;
map<char , int> hashmap2;


void func(){
	string s;
	cin>>s;
//	cout<<s.size()<<'\n';
	string res = "";
	for(int i = 1;i <= n;i++){
		bool flag = true;
		for(int j = i - 1;j < s.size();j += n){
			if(flag){
				res += s[j];
				flag = false;
			}
			else{
				res += s[j + n - j%n - i];
				flag = true;
			}
		}
	}
	cout<<res<<'\n';
	cin>>n;
}



int main(){
	cin>>n;
    while(n != 0){
        func();
    }
} 