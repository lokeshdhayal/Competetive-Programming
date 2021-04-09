#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q;
ll n , k , t,m;

void func(){
    cin>>n;
    string s;
    map< string , int > hash;
    for(int i = 0;i < n;i++){
        cin>>s;
        hash[s]++;
    }
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>s;
        cout<<hash[s]<<nl;
    }
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}

