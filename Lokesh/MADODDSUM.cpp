#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q;
ll n , k , t,m;

unsigned ll find_p(unsigned ll p){
    if(p % 2 == 0){
        p /= 2;
    }
    else{
        p = (p + 1) / 2;
    }
    return p*p;
}

void func(){
    cin>>p>>q;
    cout<<(find_p(q) - find_p(p));
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}

