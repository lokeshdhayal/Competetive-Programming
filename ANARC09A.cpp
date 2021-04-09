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
map<pi , int> hashmap;


void func(){
    int res = 0;
    int total = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '{'){
            total++;
        }
        else{
            total--;
        }
        if(total < 0){
            s[i] = '{';
            res++;
            total += 2;
        }
    }
    total = 0;
    for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] == '{'){
            total--;
        }
        else{
            total++;
        }
        if(total < 0){
            s[i] = '}';
            res++;
            total += 2;
        }
    }
    cout<<t<<". "<<res<<'\n';
}



int main(){
    cin>>s;
    while(s[0] != '-'){
        t++;
        func();
        cin>>s;
    }
} 