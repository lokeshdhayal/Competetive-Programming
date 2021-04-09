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


void func(){
    cin>>n;
    ll res = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i*j > n){
                break;
            }
            for(int k = 1;k <= n;k++){
                if(i*j*k <= n){
                    res++;
                }
                else{
                    break;
                }
            }
        }
    }
    cout<<res<<nl;
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 