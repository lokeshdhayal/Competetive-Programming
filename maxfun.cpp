#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000007
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

void func(){
    cin>>n;
    int p , q;
    vector<int> a;
    ll max1 = -MAX, max2 = -MAX , min1 = MAX , min2 = MAX;
    for(int i = 0;i < n;i++){
        cin>>temp;
        if(temp > max1){
            max1 = temp;
            p = i;
        }
        if(temp < min1){
            min1 = temp;
            q = i;
        }
        a.push_back(temp);
    }
    ll res = 0;
   // cout<<min1<<" "<<max1;
    for(int i = 0;i < n;i++){
        if(i != p && i != q){
            temp = abs(max1 - a[i]) + abs(min1 - a[i]);
            res = max(temp , res);
        }
    }
    res += abs(max1 - min1);
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 