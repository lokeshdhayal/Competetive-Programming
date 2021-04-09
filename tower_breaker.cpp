#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

int count_prime(int num){
    int count1 = 0;
    for(int i = 2;i <= num;i++){
        while(num%i == 0){
            count1 += i;
            num /= i;
        }
    }
    return count1;
}

void func(){
    cin>>n;
    ll res = 0;
    vector<int> a(n , 0);
    for(int i = 0;i < n;i++){
        cin>>temp;
        res ^= count_prime(temp);
    }
    if(res > 0){
        cout<<1<<nl;
    }
    else{
        cout<<2<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 
