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

void func(){
    cin>>n>>k;
    vector<int> res;
    for(int i = k + 1;i <= n;i++){
        res.push_back(i);
    }
    set<int> hashmap;
    for(int i = k - 1;i >= (k + 1) / 2;i--){
        res.push_back(i);
    }
    cout<<res.size()<<'\n';
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}



int main(){
    cin>>t;
    while(t--){ 
        func();
    }
} 