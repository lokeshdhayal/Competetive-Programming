#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,i,j,w1,w2,W,m,papu = 0,k,d,temp,x,y,p ,q;
int a[1001];
ll res;
int in[10005];
int lok;
int out[10005];
int timer = 0;

void find_v(int i , int j , set<string> &s , vector<vector<int> > & dp,string res,string s1 , string s2){
   // cout<<i<<" "<<j<<nl;
    if(s.size() >= 1000){
        return;
    }
    if(dp[i][j] == 0){
        reverse(res.begin() , res.end());
        s.insert(res);
        return;
    }
    if(s1[i - 1] == s2[j - 1]){
        find_v(i - 1 , j - 1 , s , dp , res + s1[i - 1] , s1 , s2);
    }
    else{
        if(dp[i][j] == dp[i - 1][j]){
            find_v(i - 1 , j , s , dp , res , s1 , s2);
        }
        if(dp[i][j] == dp[i][j - 1]){
            find_v(i , j - 1 , s , dp , res , s1 , s2);
        }
    }
}

void func(){
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int> >  dp(s1.size() + 1 , vector<int>(s2.size() + 1,0));
    for(int i = 1;i <= s1.size();i++){
        for(int j = 1;j <= s2.size();j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    set<string> s;
    find_v(s1.size(),s2.size(), s , dp , "" , s1 , s2);
    for(auto i : s){
        cout<<i<<nl;
    }
}


int main(){
    cin>>t;
    while(t--){
        func();
    }
}
