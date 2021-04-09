#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;


void func(){
    cin>>n;
    vi a(n);
    bool flag = true;
    ll sum_val = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        sum_val += temp;
        if(sum_val < (i*(i + 1) / 2)){
            flag = false;
        }
    }
    if(flag){
        cout<<"YES"<<nl;
    }
    else{
        cout<<"NO"<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 