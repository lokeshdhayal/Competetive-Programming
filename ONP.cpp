#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

int maxinP(char a){
    if(a == '+' || a == '-'){
        return 0;
    }
    else if(a == '('){
        return -1;
    }
    else{
        return 1;
    }
}

void func(){
    string s;
    cin>>s;
    string res = "";
    stack<char> st;
    for(char i : s){
        if(i == '('){
            st.push(i);
        }
        else if(i == ')'){
            while(!st.empty() && st.top() != '('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else if(i <= 'z' && i >= 'a' || i <= '9' && i >= '0'){
            res += i;
        }
        else{
            while(!st.empty() && st.top() != '(' && maxinP(st.top()) >= maxinP(i)){
                res += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty() && st.top() != '('){
        res += st.top();
        st.pop();
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 
