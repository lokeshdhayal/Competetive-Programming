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
ll n , t , m , temp , temp2, root , r , p ,q , k , res;

map<pi , int> hashmap;

int find_v(int i , int k , vector<vi> & a){
    if(hashmap.find({i , k}) != hashmap.end()){
        return hashmap[{i , k}];
    }
    if(k < 0){
        return hashmap[{i , k}] = 0;
    }
    if(i == m){
        if(k == 0){
            return hashmap[{i , k}] = 1;
        }
        return hashmap[{i , k}] = 0;
    }
    int p = 0;
    for(int j = a[i][0];j <= a[i][1];j++){
        p += find_v(i + 1 , k - j , a);
    }
    return hashmap[{i , k}] = p;
}


void func(){
    hashmap.clear();
    vector<vi> a(m , vi(2));
    for(int i = 0;i < m;i++){
        cin>>a[i][0]>>a[i][1];
    }
    cout<<find_v(0 , n , a)<<'\n';
}



int main(){
    cin>>m>>n;
    while(m != 0 && n != 0){
        func();
        cin>>m>>n;
    }
} 