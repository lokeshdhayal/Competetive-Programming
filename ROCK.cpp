#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m;
int dp[205][205];
int a[205];
int find_v(int i ,int j , string s){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i > j){
        return 0;
    }
    if(a[j + 1] - a[i] == 0){
        return dp[i][j] = 0;
    }
    if((a[j + 1] - a[i]) > (j - i + 1) / 2){
        return dp[i][j] = j - i + 1;
    }
    int res = 0;
    for(int k = i + 1;k <= j;k++){
        int p  = find_v(i , k - 1, s);
        int q = find_v(k, j , s);
        res = max(res , p + q);
      //  cout<<res<<" ";
    }
    return dp[i][j] = res;
}

void func(){
    cin>>n;
    string s;
    cin>>s;
    //cout<<s<<nl;
    a[0] = 0;
    memset(dp,  -1 , sizeof(dp));
    //a[0] = (s[0] == '1') ? 1 : 0;
    for(int i = 0;i < s.size();i++){
        a[i + 1] = (s[i] == '1') ? a[i] + 1:a[i];
    }
    cout<<find_v(0 , s.size() - 1 , s)<<"\n";
    
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}