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

bool sign_check(int a,int b){
    if(a < 0 && b > 0){
        return true;
    }
    if(a > 0 && b < 0){
        return true;
    }
    return false;
}

void func(){
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int dp[n];
    int res = 0;
    for(int i = 0;i < n;i++){
        dp[i] = 1;
        for(int j = 0;j < i;j++){
            if(sign_check(a[i] , a[j]) && abs(a[i]) > abs(a[j])){
               // cout<<i<<" "<<j<<"\n";
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
        res = max(dp[i] , res);
    }
    cout<<res;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}

