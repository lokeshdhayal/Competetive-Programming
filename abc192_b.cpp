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


bool func(string s){
	for(int i = 0;i < s.size();i++){
		if(i%2 == 0){
			if(!(s[i] <= 'z' && s[i] >= 'a'))
				return false;
		}
		else if(!(s[i] <= 'Z' && s[i] >= 'A')){
			return false;
		}
	}
	return true;
}



int main(){
    t = 1;
    while(t--){
    	string s;
    	cin>>s;
        if(func(s)){
        	cout<<"Yes"<<'\n';
        }
        else{
        	cout<<"No"<<'\n';
        }
    }
} 