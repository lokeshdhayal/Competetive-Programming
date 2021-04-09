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

int ask(int i , int j){
    if(i == j){
        return -1;
    }
    cout<<"? "<<i<<" "<<j<<nl;
    cin>>p;
    return p;
}


void func(){
    cin>>n;
    int pos = ask(1 , n);
    if(ask(1 , pos) == pos){
        ll l = 1 , r = pos;
        while(l < r){
            ll mid = (r + l + 1) / 2;
            if(ask(mid , n) == pos){
                l = mid;
            }
            else{
                r = mid - 1;
            }
        }
        cout<<"! "<<l<<nl;
    }
    else{
        ll l = pos , r = n;
        while(l < r){
            ll mid = (r + l) / 2;
            if(ask(1 , mid) == pos){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout<<"! "<<l<<nl;
    }
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 