#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,i,j,w1,w2,W,m,papu = 0,k,d,temp,x,y;
void func2(){
  //  cin>>n>>k>>x>>y;
    int counter = 0;
    k %= 4;
    if(k == 0)k = 4;
    while(n != x && n != y){
        temp = n - y;
        x += temp;
        y = n;
    }
    k--;
    if((k == 0) || (x == n && y == n)){
        cout<<x<<" "<<y<<nl;
        return;
    }
    while(n != x){
        temp = n - x;
        y -= temp;
        x = n;
    }
    k--;
    if(k == 0){
        cout<<x<<" "<<y<<nl;
        return;
    }
    while(y != 0){
        x -= y;
        y = 0;
    }
    k--;
    if(k == 0){
        cout<<x<<" "<<y<<nl;
        return;
    }
    while(x != 0){
        y += x;
        x = 0;
    }
    k--;
    if(k == 0){
        cout<<x<<" "<<y<<nl;
        return;
    }
}
//int a[1005],b[1005];
void func(){
    cin>>n>>k>>x>>y;
    if(y > x){
        func2();
        return;
    }
    int counter = 0;
    k %= 4;
    if(k == 0)k = 4;
    while(n != x && n != y){
        temp = n - x;
        x = n;
        y += temp;
    }
    k--;
    if((k == 0) || (x == n && y == n)){
        cout<<x<<" "<<y<<nl;
        return;
    }
    while(n != y){
        temp = n - y;
        x -= temp;
        y = n;
    }
    k--;
    if(k == 0){
        cout<<x<<" "<<y<<nl;
        return;
    }
    while(x != 0){
        y-=x;
        x = 0;
    }
    k--;
    if(k == 0){
        cout<<x<<" "<<y<<nl;
        return;
    }
    while(y != 0){
        x+=y;
        y = 0;
    }
    k--;
    if(k == 0){
        cout<<x<<" "<<y<<nl;
        return;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
