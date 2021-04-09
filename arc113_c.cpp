#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;


void func(){
	string s;
	ll res = 0;
	cin>>s;
	vector<int> hash(26 , 0);
	for(int i = s.size() - 1;i >= 1;i--){
		if(s[i] == s[i - 1]){
			for(int j = 0;j < 26;j++){
				if(s[i] - 'a' != j){
					res += hash[j];
					hash[s[i] - 'a'] += hash[j];
					hash[j] = 0;
				}
			}
		}
		hash[s[i] - 'a']++;
	}
    cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 