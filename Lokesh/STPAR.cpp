#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
int a[1005];
ll n;

void func(){
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int prev = 0;
    stack<int> st;
    for(int i = 0;i < n;i++){
        while(!st.empty() && prev + 1 == st.top()){
            prev = st.top();
            st.pop();
        }
      //  cout<<st.top()<<" ";
        if(a[i] == prev + 1){
            prev = a[i];
        }
        else if(st.empty() || st.top() > a[i]){
            st.push(a[i]);
        }
        else{
            cout<<"no"<<nl;
            return;
        }
       // cout<<st.size()<<" ";
    }
    cout<<"yes"<<nl;
}

int main(){
    cin>>n;
    while(n != 0){
        func();
        cin>>n;
    }
}