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

int max_p(int a,int b){
    if(a > b){
        return a;
    }
    return b;
}

void func(){
    cin>>n>>k;
    set<int> b;
    vector<int> a;
    int temp;
    for(int i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp%k);
        b.insert(temp%k);
    }
    for(int i = 0;i < n;i++){
        if(a[i] != 0 && b.find((k - a[i])) == b.end()){
            cout<<"NO"<<nl;
            return;
        }
    }
    cout<<"YES"<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}