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

bool check(ll mid){
	for(int i = 0;i < 26;i++){
		if(hashmap1[i + 'a']*mid > hashmap2[i + 'a']){
			return false;
		}
		if(hashmap1[i + 'A']*mid > hashmap2[i + 'A']){
			return false;
		}
	}
	return true;
}


void func(){
	string s1 , s2;
	cin>>s1>>s2;
	for(char i : s1){
		hashmap1[i]++;
	}
	for(char i : s2){
		hashmap2[i]++;
	}
	ll res = 0;
	ll low = 0;
	ll high = ceil((double)s2.size() / s1.size());
	//cout<<low<<" "<<high<<'\n';
	while(low <= high){
		ll mid = (high - low) / 2 + low;
		if(check(mid)){
			res = max(res , mid);
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	//	cout<<mid<<" "<<check(mid)<<"\n";
	}
	cout<<res<<'\n';
	hashmap1.clear();
	hashmap2.clear();
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 