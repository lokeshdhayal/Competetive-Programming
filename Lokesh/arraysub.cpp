#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
ll n , k , t,m;
int a[1000005];

void func(){
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    cin>>k;
    deque<int> dq;
    int i = 0,j = 0;
    while(j < n){
        while(!dq.empty() && dq.back() < a[j]){
            dq.pop_back();
        }
        dq.push_back(a[j]);
        if((j - i + 1) == k){
            cout<<dq.front()<<" ";
            if(a[i] == dq.front()){
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}