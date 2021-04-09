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
using tint = tuple<int, int, int>; 
ll n , t , m , temp , temp2 ,p , q ,  r , root;

map<vector<int> , int > dp;

int f(int  a , int b){
    if(!b){
        return 1;
    }
    int r = f(a , b / 2);
    return r*r*(b%2 == 0 ? 1 : a)%10;
}


int calc(int a , int b , int c){
    vector<int> p(3);
    p[0] = a;
    p[1] = b;
    p[2] = c;
    if(!c){
        return a;
    }
    if(dp.count(p)){
        return dp[p];
    }
    int & r = dp[p];
    r = calc(calc(a , b , c / 2)%10 , b , c / 2);
    if(c%2){
        r = f(r , b);
    }
    return r;
}

void func(){
    int a, b , c;
    cin>>a>>b>>c;
    cout<<calc(a , b  , c)<<nl;
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 