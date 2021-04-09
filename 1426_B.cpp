#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;

void func(){
    cin>>m>>n;
    bool flag = false;
    bool flag1 = false;
    vector<vector<int> > dp;
    while(m--){
        cin>>p>>q>>r>>s;
        if(p == s && q == r){
            flag = true;
        }
        if(q == r){
            flag1 = true;
        }
    }
    //cout<<"yes";

    if(n%2 != 0){
        cout<<"NO"<<nl;
        return;
    }
    if(flag == true){
        cout<<"YES"<<nl;
        return;
    }
    if(flag1 == false){
        cout<<"NO"<<nl;
        return;
    }
    cout<<"YES"<<nl;
  /*  for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if(dp[i][2] == dp[j][1] && dp[j][2] == dp[j][2] && dp[i][0] == dp[j][0] && dp[i][3] == dp[j][3]){
                flag1 = true;
                break;
            }
        }
        if(flag1){
            break;
        }
    }
    if(flag1){
        cout<<"YES"<<nl;
    }
    else{
        cout<<"NO"<<nl;
    }*/
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 