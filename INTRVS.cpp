#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q , r , x = 0;
ll n , k , t,m;

void func(){
    cin>>n>>k;
    bool flag = true;
    bool flag2 = true;
    int sum = 0,count1 = 0,temp;
    for(int i = 0;i < n;i++){
        cin>>temp;
        sum += temp;
        if(temp != -1){
            count1++;
        }
        if(temp > k){
            flag2 =  false;
        }
        if(temp > 1){
            flag = false;
        }
    }
   // cout<<sum;
    if((n+1)/2 > count1){
        cout<<"Rejected"<<nl;
        return;
    }
    if(!flag2){
        cout<<"Too Slow"<<nl;
        return;
    }
    if(flag && count1 == n){
        cout<<"Bot"<<nl;
        return;
    }
    cout<<"Accepted"<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}