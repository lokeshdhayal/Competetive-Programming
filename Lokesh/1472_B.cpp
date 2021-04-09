#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,i,j,result;


void func(){
    cin>>n;
    ll sum = 0;
    ll count_2 = 0;
    ll count_1 = 0;
    for(i = 0;i < n;i++){
        cin>>temp;
        sum += temp;
        if(temp == 1){
            count_1++;
        }
        else{
            count_2++;
        }
    }
    if(sum % 2 != 0){
        cout<<"NO"<<nl;
        return;
    }
    if(count_2 % 2 == 0 && count_1 % 2 == 0){
        cout<<"YES"<<nl;
        return;
    }
    if(count_2 % 2 != 0 && count_1 %2 == 0 && count_1 >= 2){
        cout<<"YES"<<nl;
        return;
    }
    if(count_1 % 2 != 0){
        cout<<"NO"<<nl;
        return;
    }

    cout<<"NO"<<nl;
    return;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
