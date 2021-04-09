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
    cin>>m>>n;
    long long dp[n + 1][m + 1];
    cout<<m<<" "<<n<<nl;
    memset(dp , 0 , sizeof(dp));
    vector<ll> a(n);
    vector<ll> b(n);
    for(ll i = 0;i < n;i++){
        cin>>a[i]>>b[i];
    }
    for(ll i = 0;i <= n;i++){
        for(ll j = 0;j <= m;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else if(j >= a[i - 1]){
                dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - a[i - 1]] + b[i - 1]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    cout<<dp[n][m]<<nl;
   // cin>>m>>n;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
} 