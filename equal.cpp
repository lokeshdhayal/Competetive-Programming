#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m;

void find_v(vector<int> a , int min_v){
    int res = 0;
    for(int i = 0;i < a.size();i++){
        if(a[i] > min_v){
            a[i] = a[i] - min_v;
            res += a[i] / 5;
            a[i] = a[i]%5;
            res += a[i] / 2;
            a[i] = a[i] % 2;
            if(a[i]){
                res++;
            } 
        }
    }
    return res;
}


void func(){
    cin>>n;
    int min_v = mod;
    vector<int> a;
    for(int i = 0;i < n;i++){
        cin>>temp;
        if(temp < min_v){
            min_v = temp;
        }
        a.push_back(temp);
    }
    ll count1 = find_v(a , min_v);
    ll count2 = find_v(a , min_v - 1);
    ll count3 = find_v(a , min_v - 2);
    cout<<min(count1 , min(count2 , count3))<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}