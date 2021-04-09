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
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	string res = "";
	bool flag = true;
	int i = 0;
	int j = 0;
	do{
		if(s1[i] != s2[j]){
			flag = false;
			break;
		}
		res += s1[i];
		i++;
		j++;
		i = i % (s1.size());
		if(j == s2.size()){
			j = 0;
		}
	//	cout<<i<<" "<<j<<" "<<s1.size()<<" "<<s2.size()<<"\n";
	}while(i != 0 || j != 0);
	if(flag){
		cout<<res<<'\n';
	}
	else{
		cout<<-1<<'\n';
	}
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 