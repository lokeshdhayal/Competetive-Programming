#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

stack<int> st;

void func(){
    cin>>n;
    if(n == 1){
        cin>>m;
        st.push(m);
        return;
    }
    if(n == 2){
        if(!st.empty()){
            st.pop();
        }
        return;
    }
    if(st.empty()){
        cout<<"Empty!"<<nl;
    }
    else{
        cout<<st.top()<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 