#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q , r , x = 0;
ll n , k , t , m;
//int dp[100005];

int max_p(int a,int b){
    if(a > b){
        return a;
    }
    return b;
}

void func(){
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(s.size() + 1 , 0);
    vector<int> b(s.size() + 1 , 0);
    if(s[0] == '0'){
        a[0]++;
    }
    for(int i = 1;i < s.size();i++){
        if(s[i] == '0'){
            a[i] = a[i - 1] + 1;
        }
        else{
            a[i] = a[i - 1];
        }
    }
    if(s[s.size() - 1] == '1'){
        b[0]++;
    }
    for(int i = s.size() - 1;i >= 0;i--){
        if(s[i] == '1'){
            b[i] = b[i + 1] + 1;
        }
        else{
            b[i] = b[i + 1];
        }
    }
    int res = 0;
    for(int i = 0;i < s.size();i++){
      //  cout<<a[i]<<" "<<b[i+1]<<nl;
        if(a[i] + b[i+1] > res){
            res = a[i] + b[i + 1];
        }
    }
    res = max(res , b[0]);
    cout<<(n - res)<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}