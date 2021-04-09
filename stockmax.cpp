#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;


void func(){
    cin>>n;
    int dp[n + 1][2];
    vector<int> a;
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(int i = 1;i <= n;i++){
        dp[i][0] = max(dp[i - 1][0] , dp[i-1][1]);
        dp[i][0] += a[i - 1];
        dp[i][1] = max(dp[i-1][0] + a[i - 1] , dp[i-1][1]);
    }
    cout<<max(dp[n][0] , dp[n][1]);
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 