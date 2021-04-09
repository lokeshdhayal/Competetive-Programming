#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"


void func(){
    long double n , k , m;
    cin>>n>>k>>m;
    ll res = 0;
    while(m / k >= n){
        n *= k;
        res++;
    }
    cout<<res<<nl;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        func();
    }
}


3*2 = 6
1 2 3

100 * 99 

5

5!
5 / 
1 4
//2 4
//3 4
1 3
2 3
//4 3
1 2
//2 1


