#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;

int gcd(int a , int b , int & x , int & y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int x1 ,y1;
    int d = gcd(b , a%b , x1 , y1);
    x = y1;
    y = x1 - y1*(a / b);
    return d;
}


bool find_sol(int a , int b , int c , int & x , int & y){
    int g = gcd(abs(a) , abs(b) , x , y);
    if(c % g){
        return false;
    }

    x *= c / g;
    y *= c / g;
    return true;
}


void func(){
    int a , b , c;
    cin>>a>>b>>c;
    int x = 0 , y = 0;
    if(find_sol(a , b , c , x , y )){
        cout<<(abs(x) + abs(y))<<x<<" "<<y<<nl;
    }
    else{
        cout<<-1<<nl;
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 