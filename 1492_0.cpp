#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root;

ll solve(int p , int b){
  /*  if(b%p == 0){
        return b;
    }*/
    int l = 1;
    ll res = LONG_MAX;
    int r = p;
    while(l <= r){
        ll mid = (r - l)/2 + l;
        if(mid * b * 1L >= p){
            res = min(mid , res);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return b*res;
}


void func(){
    ll p , a , c , b , a_min , b_min , c_min , r;
    cin>>p>>a>>b>>c;
    a_min = a - p%a;
    if(a_min == a){
        a_min = 0;
    }
    b_min = b - p%b;
    if(b_min == b){
        b_min = 0;
    }
    c_min = c - p%c;
    if(c_min == c){
        c_min = 0;
    }
    cout<<min(a_min , min(b_min , c_min))<<'\n';
}



int main(){
  //  cout<<solve(10 , 10);
    cin>>t;
    while(t--){
        func();
    }
} 