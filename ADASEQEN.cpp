#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

typedef vector<ll> vi;
ll p,q;
ll n , k , t,m;

void func(){
    cin>>n>>m;
    int a[26];
    for(int i = 0;i < 26;i++){
        cin>>a[i];
    }
    string s1,s2;
    cin>>s1;
    cin>>s2;
    vector<vi> dp(s1.size() + 1 , vi(s2.size() + 1 , 0));
    for(int i = 1;i <= s1.size();i++){
        for(int j = 1;j <= s2.size();j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + a[s1[i - 1] - 'a'];
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    cout<<dp[s1.size()][s2.size()];
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}

