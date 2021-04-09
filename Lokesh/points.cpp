#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,x,t,m,k,count1,result;


void func(){
    vector<pair<int , int> > a;
    cin>>n;
    while(n--){
        cin>>p>>q;
        a.push_back({ p , q});
    }
    bool flag1 = true, flag2 = true;
    p = a[0].first;
    q = a[0].second;
    for(int i = 1;i < a.size();i++){
        if(a[i].first != p){
            flag1 = false;
        }
        if(a[i].second != q){
            flag2 = false;
        }
    }
    if(flag1 || flag2){
        cout<<"YES"<<nl;
        return;
    }
    cout<<"NO"<<nl;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}