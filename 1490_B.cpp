#include<iostream>
#include <bits/stdc++.h>
using namespace std;
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
    ll c0 = 0;
    ll c1 = 0;
    ll c2 = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        if(temp%3 == 0){
            c0++;
        }
        else if(temp%3 == 1){
            c1++;
        }
        else{
            c2++;
        }
    }
    if(c0 == c1 && c2 == c0){
        cout<<0<<'\n';
        return;
    }
    int p = n / 3;
    ll res = 0;
    while(c0 != c1 || c0 != c2){
        if(c0 > p){
            r = c0 - p;
            c0 = p;
            c1 += r;
            res += r;
        }
        else if(c1 > p){
            r = c1 - p;
            c1 = p;
            c2 += r;
            res += r;
        }
        else{
            r = c2 - p;
            c2 = p;
            c0 += r;
            res += r;
        }
    }
    cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 