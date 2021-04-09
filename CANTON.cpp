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
    cin>>n;
    ll res = ceil(sqrt(2*n - 0.25) - 0.5);
    if(res == 1){
        cout<<"TERM 1 IS 1/1"<<nl;
        return;
    }
    r = ((res * (res - 1)) / 2);
    r = n - r;
  //  cout<<res<<" "<<r<<nl;
    if(res%2 == 0){
        cout<<"TERM "<<n<<" IS "<<r<<"/"<<(res + 1 - r)<<nl;
    }
    else{
        cout<<"TERM "<<n<<" IS "<<(res + 1 - r)<<"/"<<(r)<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 