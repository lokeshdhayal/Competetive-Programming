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


ll solve(string & a , int i , int j,vector<vi> & dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == j){
        return dp[i][j] = (a[i] - '0');
    }
    ll res = 0;
    for(int k = i + 1;k < j;k += 2){
        ll left = solve(a , i , k - 1 , dp);
        ll right = solve(a , k + 1 , j , dp);
        if(a[k] == '*'){
            res = max(res , left * right);
        }
        else{
            res = max(res , left + right);
        }
    }
    return dp[i][j] = res;
}

ll solve1(string & a , int i , int j,vector<vi> & dp){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == j){
        return dp[i][j] = (a[i] - '0');
    }
    ll res = LONG_MAX;
    for(int k = i + 1;k < j;k += 2){
        ll left = solve1(a , i , k - 1 , dp);
        ll right = solve1(a , k + 1 , j , dp);
        if(a[k] == '*'){
            res = min(res , left * right);
        }
        else{
            res = min(res , left + right);
        }
    }
    return dp[i][j] = res;
}

void func(){
    string s;
    cin>>s;
    vector<vi> dp(s.size() , vi(s.size() , -1));
    vector<vi> dp1(s.size() , vi(s.size() , -1));
    cout<<solve(s , 0 , s.size() - 1 , dp)<<" "<<solve1(s , 0 , s.size() - 1 , dp1)<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 