#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp1 , temp2;

void func(){
    ll dp[n + 1][m + 1];
    //cout<<m<<" "<<n<<nl;
    memset(dp , 0 , sizeof(dp));
    vector<ll> a;
    vector<ll> b;
    for(ll i = 0;i < n;i++){
        cin>>temp1;
        cin>>temp2;
        a.push_back(temp1);
        b.push_back(temp2);
    }
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= m;j++){
            dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            if(j >= a[i - 1]){
                dp[i][j] = max(dp[i][j] , dp[i - 1][j - a[i - 1]] + b[i - 1]);
            }
        }
    }
    ll res1 = -1,res2 = -1;
    for(ll i = 0;i <= m;i++){
        if(dp[n][i] > res1){
            res1 = dp[n][i];
            res2 = i;
        }
    }
    cout<<res2<<" "<<res1<<nl;
    cin>>m>>n;
}

int main(){
    cin>>m>>n;
    while(m != 0 && n != 0){
        func();
    }
} 