#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;

int a[MAX];

void find_p(int i,int sum){
    if(sum % k == 0){
        result++;
    }
    if(i > n){
        return;
    }
    find_p(i + 1,a[i] + sum);
}

void func(){
    cin>>n>>k;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n - 1;i++){
        find_p(i + 1,a[i]);
    }
    cout<<result<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
