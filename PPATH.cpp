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
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , p ,q , k;

set<string> s;

void sieve(){
    vector<bool> a(10000 , false);
    for(int i = 2;i < 10000;i++){
        if(a[i] == false){
            for(int j = i*i;j < 10000;j += i){
                a[j] = true;
            }
        }
    }
    for(int i = 1000;i <= 9999;i++){
        if(a[i] == false){
            s.insert(to_string(i));
        }
    }
} 

void func(){
    string l , r;
    cin>>l>>r;
    if(l == r){
        cout<<0<<'\n';
        return;
    }
    queue<pair<string , int> > q;
    q.push({l , 1});
    set<string> s2;
    s2.insert(l);
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            char lok = front.first[i];
            for(int j = 0;j <= 9;j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(j == lok - '0'){
                    continue;
                }
                front.first[i] = (j + '0');
                if(s.find(front.first) != s.end() && s2.find(front.first) == s2.end()){
                    if(front.first == r){
                        cout<<front.second<<'\n';
                        return;
                    }
                    s2.insert(front.first);
                    q.push({front.first , front.second + 1});
                }
                front.first[i] = lok;
            }
            front.first[i] = lok;
        } 
    }
    cout<<"Impossible"<<'\n';
}



int main(){
    cin>>t;
 //   cout<<(s.find("8019") != s.end())<<'\n';
    sieve();
    while(t--){
        func();
    }
} 