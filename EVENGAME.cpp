#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q , r , x = 0;
ll n , k , t , m;
//int dp[100005];


void func(){
    cin>>n;
    vector<int> a;
    int temp;
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        sum = (sum + temp)%2;
    }
    if(sum == 0){
        cout<<1<<nl;
    }
    else{
        cout<<2<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}