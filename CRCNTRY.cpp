#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 , r , root;

int lcs(vector<int> a , vector<int> b){
    int dp[a.size() + 1][b.size() + 1];
   /* for(int i  = 0;i < a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<nl;
    for(int i  = 0;i < b.size();i++){
        cout<<b[i]<<" ";
    }
    cout<<nl;*/
    for(int i =  0;i <= a.size();i++){
        for(int j = 0;j <= b.size();j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }
    }
    return dp[a.size()][b.size()];
}


void func(vector<int> p){
    int res = 0;
    //cout<<"yes";
    while(true){
        cin>>temp;
        if(temp == 0){
            break;
        }
        vector<int> q;
        while(temp != 0){
            q.push_back(temp);
            cin>>temp;
        }
        res = max(res , lcs(p , q));
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        vector<int> p;
        cin>>temp;
        while(temp != 0){
            p.push_back(temp);
            cin>>temp;
        }
        func(p);
    }
} 