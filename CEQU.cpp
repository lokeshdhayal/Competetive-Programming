#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root , a , b , c , i;

int gcd(int a , int b){
    if(b == 0){
        return a;
    }
    return gcd(b , a%b);
}


bool find_v(int a , int b , int c){
    if(a == c || b == c || a + c == c){
        return true;
    }
    return c%gcd(a , b) == 0;
}

void func(){
    cin>>a>>b>>c;
    if(find_v(a , b , c)){
        cout<<"Case "<<i<<":"<<" Yes"<<nl;
    }
    else{
        cout<<"Case "<<i<<":"<<" No"<<nl;
    }
}



int main(){
    cin>>t;
    for (i = 1; i <= t; ++i)
    {
        func();
    }
} 