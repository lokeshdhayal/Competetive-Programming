#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
ll n , k , t,m;

void func(){
    cin>>n>>m;
    ll a[26];
    for(int i = 0;i < 26;i++){
        cin>>a[i];
    }
    string s1,s2;
    cin>>s1;
    cin>>s2;
    ll dp[m + 1][n + 1];
    memset(dp , 0 , sizeof(dp));
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            dp[i][j] = max(dp[i][j - 1] , dp[i - 1][j]);
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = max(dp[i - 1][j - 1] + a[s1[i - 1] - 'a'], dp[i][j]);
            }
        }
    }
    cout<<dp[m][n];
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}

