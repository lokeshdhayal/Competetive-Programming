#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
ll n , k , t,m;
//int a[1000005];

void func(){
    cin>>n>>k;
    stack<int> neg;
    stack<int> pos;
    ll sum = 0;
    for(int i = n;i >= 1;i--){
        if(sum <= k){
            sum += i;
            pos.push(i);
        }
        else{
            sum -= i;
            neg.push(i);
        }
    }
    if(sum == k){
        if(neg.empty()){
            cout<<pos.top();
            pos.pop();
            while(!pos.empty()){
                cout<<"+"<<pos.top();
                pos.pop();
            }
            return;
        }
        if(neg.top() < abs(pos.top())){
            cout<<"-"<<neg.top();
            neg.pop();
        }
        else{
            cout<<pos.top();
            pos.pop();
        }
        while(!neg.empty() && !pos.empty()){
            if(neg.top() < pos.top()){
                cout<<"-"<<neg.top();
                neg.pop();
            }
            else{
                cout<<"+"<<pos.top();
                pos.pop();
            }
        }
        while(!neg.empty()){
            cout<<"-"<<neg.top();
            neg.pop();
        }
        while(!pos.empty()){
            cout<<"+"<<pos.top();
            pos.pop();
        }
    }
    else{
        cout<<"Impossible"<<nl;
    }
    
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}