#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;


void func(){
    string s;
    cin>>s;
    bool flag = true;
    for(int i = 0;i < s.size();i++){
        if(flag){
            if(s[i] == 'a'){
                s[i] = 'b';
            }
            else{
                s[i] = 'a';
            }
            flag = false;
        }
        else{
            if(s[i] == 'z'){
                s[i] = 'y';
            }
            else{
                s[i] = 'z';
            }
            flag = true;
        }
    }
    cout<<s<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 