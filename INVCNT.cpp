#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 10000000
#define nl "\n"
ll n , t , m , temp , temp2 , p , q , r , root;

int a[10000001];


ll find_sum(int i){
    ll sum = 0;
    while(i > 0){
        sum += a[i];
        i -= (i & -i);
    }
    return sum;
}


void update(int i){
    while(i <= MAX){
        a[i]++;
        i += (i & -i);
    }
}


void func(){
    memset(a , 0 , sizeof(a));
    cin>>n;
    ll result = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        result += find_sum(MAX) - find_sum(temp);
        update(temp);
    }
    cout<<result<<'\n';
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 