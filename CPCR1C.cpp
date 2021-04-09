#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/profile/kazama460
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

map<pair<pair<ll ,ll >, bool >,ll> hashmap;

ll getAns(ll pos , string s , bool flag , ll sum){
	if(pos > s.size()){
		return sum;
	}
	if(hashmap.find({{pos , sum} , flag}) != hashmap.end()){
		return hashmap[{{pos , sum} , flag}];
	}
	int max_limit = 9;
	if(flag == false){
		max_limit = s[pos - 1] - '0';
	}
	ll res = 0;
	for(int i = 0;i <= max_limit;i++){
		if(flag || i < max_limit){
			res += getAns(pos + 1 , s , true , sum + i);
		}
		else{
			res += getAns(pos + 1 , s , false , sum + i);
		}
	}
	return hashmap[{{pos , sum} , flag}] = res;
}


void func(){

	ll ans;
	hashmap.clear();
	if(m != 0)
	{
		hashmap.clear();
		ans = getAns(1 , to_string(n) , false , 0);
		hashmap.clear();
		ans -= getAns(1 , to_string(m - 1) , false , 0);
	}
	else
		ans = getAns(1 , to_string(n) , false , 0);
	cout<<ans<<'\n';
}



int main(){
	cin>>m>>n;
    while(m != -1 && n != -1){
        func();
        cin>>m>>n;
    }
} 