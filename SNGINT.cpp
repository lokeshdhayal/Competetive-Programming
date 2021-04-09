#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 , p , q , r , root;

void func(int n){
    if(n == 0){
        cout<<"10"<<nl;
        return;
    }
    int count2 = 0 , count3 = 0 , count5 = 0 , count7 = 0;
    while(n%2 == 0){
        n /= 2;
        count2++;
    }
    while(n%3 == 0){
        n /= 3;
        count3++;
    }
    while(n%5 == 0){
        n /= 5;
        count5++;
    }
    while(n%7 == 0){
        n /= 7;
        count7++;
    }
    string res = "";
    if(n > 1){
        cout<<-1<<nl;
        return;
    }
    while(count7--){
        res += '7';
    }
  //  cout<<res<<nl;
    while(count5--){
        res += '5';
    }
  //  cout<<res<<nl;
    while(count3/2 >= 1){
        res += '9';
        count3 -= 2;
    }
 //   cout<<res<<nl;
    while(count2/3 >= 1){
        res += '8';
        count2 -= 3;
    }
  //  cout<<res<<nl;
    if(count3 == 1 && count2 >= 1){
        res += '6';
        count3--;
        count2--;
    }
   // cout<<res<<nl;
    if(count2 > 1){
        count2 -= 2;
        res += '4';
    }
    if(count2 > 0){
        count2--;
        res += '2';
    }
    if(count3 > 0){
        res += '3';
    }
   // cout<<res<<nl;
    sort(res.begin() , res.end());
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n;
        func(n);
    }
} 