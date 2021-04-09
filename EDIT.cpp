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
string s;
map<pair<vector<bool> , ll >, ll> hashmap;

ll find_v(vector<int>  adj[] , vector<bool> & vis , int i){
    if(i == n){
        return 1;
    }
    if(hashmap.find({vis , i}) != hashmap.end()){
        return hashmap[{vis , i}];
    }
    ll res = 0;
    for(int j : adj[i]){
        if(vis[j] == false){
            vis[j] = true;
            res += find_v(adj , vis , i + 1);
            vis[j] = false;
        }
    }
    return res;
}


void func(){
    int res1 = 0;
    int res2 = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] >= 'a' && s[i] <= 'z' && i % 2 == 0){
            res1++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z' && i % 2 == 1){
            res1++;
        }
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] >= 'a' && s[i] <= 'z' && i % 2 == 1){
            res2++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z' && i % 2 == 0){
            res2++;
        }
    }
    cout<<min(res1 , res2)<<'\n';
}



int main(){
    while(cin>>s){
        func();
    }
} 