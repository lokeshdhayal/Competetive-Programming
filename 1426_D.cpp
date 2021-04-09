#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;


void func(){
    cin>>n;
    set<ll> s;
    s.insert(0);
    ll res = 0;
    ll sum_t = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        sum_t += temp;
        if(s.find(sum_t) != s.end()){
            res++;
            s.clear();
            s.insert(temp);
            s.insert(0);
            sum_t = temp;
        }
        else{
            s.insert(sum_t);
        }
    }
    cout<<res<<nl;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
} 