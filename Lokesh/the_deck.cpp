#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;

ll a[1000];
ll F[505];

bool comp(string p,string res,ll x){
    if(res == ""){
        return true;
    }
    cout<<x<<" "<<p.size()<<nl;
    while(x < p.size() && x < res.size()){
        if(p[x] < res[x]){
            return true;
        }
        else if(p[x] > res[x]){
            return false;
        }
        x++;
    }
    if(res.size() < x){
        return true;
    }
    return false;
}

void func(){
    cin>>
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}
