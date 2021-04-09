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


void func(){
    cin>>n;
    string lok;
    cin>>lok;
    ll count1 = 0;
    ll count0 = 0;
    for(int i = 0;i < n;i++){
        if(lok[i] == '0' && i % 2 == 0){
            count1++;
        }
        if(i % 2 == 1 && lok[i] == '1'){
            count1++;
        }
        if(i % 2 == 0 && lok[i] == '1'){
            count0++;
        }
        if(i % 2 == 1 && lok[i] == '0'){
            count0++;
        }
    }
    if(count0 > count1){
        cout<<count1;
        return;
    }
    cout<<count0<<nl;
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}
