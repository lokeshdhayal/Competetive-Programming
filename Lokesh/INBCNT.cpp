#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
ll n , k , t,m;
//int a[1000005];

int S(int n , int m){
    if(m == 0 && n == 0){
        return 1;
    }
    if(m == 0 || n == 0){
        return 0;
    }
    return m * S(n-1,m) + S(n - 1,m - 1);
}

void func(){
    cin>>n>>k;
    cout<<S(n,k)<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}

