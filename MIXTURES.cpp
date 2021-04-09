#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2 ,p , q ,  r , root;


int solve(vi & a , int i , int j,vector<vi> & dp){
   // cout<<i<<" "<<j<<'\n';
    if(j - i + 1 < 2){
        return dp[i][j] = 0;
    }
    if(j - i + 1 == 2){
        return dp[i][j] = a[i] * a[j];
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll res = LONG_MAX;
    for(int k = i;k < j;k++){
        ll ans = solve(a , i , k , dp) + solve(a , k + 1 , j , dp);
        int sum_val1 = 0;
        int sum_val2 = 0;
        for(int l = i;l <= k;l++){
            sum_val1 = (sum_val1 + a[l]) % 100;
        }
        for(int l = k + 1;l <= j;l++){
            sum_val2 = (sum_val2 + a[l]) % 100;
        }
      //  cout<<ans<<" "<<sum_val1<<" "<<sum_val2<<" "<<i<<" "<<j<<'\n';
        ans += sum_val1 * sum_val2;
        res = min(ans , res);
    }
  //  cout<<i<<" "<<j<<" "<<res<<"Lokesh"<<"\n";
    return dp[i][j] = res;
}

void func(){
    vi a;
    vector<vi> dp(n , vi(n , -1)); 
    for(int i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    cout<<solve(a , 0 , a.size() - 1 , dp)<<'\n';
   /* for(int i = 0;i < dp.size();i++){
        for(int j = 0;j < dp[i].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }*/
}



int main(){
    while(cin>>n){
        func();
    }
} 