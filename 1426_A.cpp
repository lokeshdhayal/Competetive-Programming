#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 , r , root;

void func(){
    cin>>m>>n;
    if(m <= 2){
        cout<<1<<nl;
        return;
    }
    m -= 2;
    //n--;
    cout<<(ceil((float)m/n) + 1)<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 