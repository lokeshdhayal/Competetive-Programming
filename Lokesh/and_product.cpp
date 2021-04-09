#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q , r , x = 0;
ll n , k , t,m;

void func(){
    cin>>m>>n;
    int res=  0;
    for(int i = 30;i >= 0;i--){
        if(((1 << i) & m) != ((1 << i) & n)){
            break;
        }
        else{
            res |= (1 << i) & m;
        }
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}

