#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q , r , x = 0;
ll n , k , t,m;

void func(){
    cin>>n;
    int temp;
    int even = 0, odd = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        if(temp % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }
    cout<<min(even , odd)<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}