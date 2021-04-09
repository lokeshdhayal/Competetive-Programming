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

void func(int n){
    if(n == 1){
        cout<<4<<nl;
        return;
    }
    if(n == 2){
        cout<<4<<nl;
        return;
    }
    cout<<((n + 1)*(n + 1) - 4)<<nl;
}



int main(){
    t = 1;
    while(t--){
        cin>>n;
        func(n);
    }
} 