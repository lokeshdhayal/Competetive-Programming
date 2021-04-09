#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
ll n , k , t,m,r;
//int a[1000005];

void make_p(vector< vector<int> > & res , int p , int q,int r){
    vector<int> a(4);
    a[0] = p,a[1] = q,a[2] = r,a[3] = p * q;
    res.push_back(a);
    a[0] = r,a[1] = q,a[2] = p,a[3] = r * q;
    res.push_back(a);
    a[0] = p,a[1] = r,a[2] = q,a[3] = p * r;
    res.push_back(a);
}

bool comp(vector<int> a,vector<int> b){
    if(a[3] > b[3]){
        return true;
    }
    return false;
}

bool check(vector<int> a,vector<int> b){
    if(a[1] < b[1] && a[0] < b[0]){
        return true;
    }
    if(a[0] < b[1] && a[1] < b[0]){
        return true;
    }
    return false;
}

void func(){
    vector< vector<int> > res;
    for(int i = 0;i < n;i++){
        cin>>p>>q>>r;
        make_p(res , p , q , r);
    }
    sort(res.begin(),res.end() , comp);
    int dp[res.size() + 1];
    int result = 0;
    memset(dp , 0 ,sizeof(dp));
    for(int i = 0;i < res.size();i++){
        dp[i] = res[i][2];
        for(int j = 0;j < i;j++){
            if(check(res[i],res[j])){
                dp[i] = max(dp[j] + res[i][2],dp[i]);
            }
        }
        result = max(result , dp[i]);
    }
    cout<<result<<nl;
}

int main(){
    cin>>n;
    while(n != 0){
        func();
        cin>>n;
    }
}