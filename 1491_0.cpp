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
ll n , t , m , temp , temp2, temp1 , root , r , p ,q , k;


void func(){
	cin>>m>>n;
	int count_0 = 0;
	int count_1 = 0;
	map<int, int> hashmap;
	for(int i = 0;i < m;i++){
		cin>>temp;
		if(temp == 0){
			count_0++;
		}
		else{
			count_1++;
		}
		hashmap[i] = temp;
	}
	while(n--){
		cin>>temp;
		if(temp == 1){
			cin>>temp2;
			if(hashmap[temp2 - 1] == 1){
				count_1--;
				count_0++;
			}else{
				count_0--;
				count_1++;
			}
			hashmap[temp2 - 1] = 1 - hashmap[temp2 - 1];
		}
		else if(temp == 2){
			cin>>temp2;
			if(count_1 >= temp2)
			{
				cout<<1<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
		}
	}
}



int main(){
	t = 1;
    while(t--){
        func();
    }
}