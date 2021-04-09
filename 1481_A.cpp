#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;

ll gcd(ll a ,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b , a%b);
}


void func(){
    ll x , y;
    cin>>x>>y;
    string s;
    cin>>s;
    int R = 0;
    int L = 0;
    int U = 0;
    int D = 0;
    for(char i : s){
        if(i == 'U'){
            U++;
        }
        if(i == 'D'){
            D++;
        }
        if(i == 'L'){
            L++;
        }
        if(i == 'R'){
            R++;
        }
    }
    if(x > 0 && R < x){
        cout<<"NO"<<'\n';
        return;
    }
    else if(x < 0 && L < abs(x)){
        cout<<"NO"<<'\n';
        return;
    }
    if(y > 0 && U < y){
        cout<<"NO"<<'\n';
        return;
    }
    else if(y < 0 && D < abs(y)){
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';

}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 