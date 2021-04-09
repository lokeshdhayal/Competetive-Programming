#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
ll n , t , m;

void func(){
    cin>>n;
    vi a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    vi ans;
    int l = -1;
    for(int i = 0;i < n;i++){
        auto p = lower_bound(ans.begin() , ans.end() , a[i]);
        if(p == ans.end()){
            ans.push_back(a[i]);
        }
        else{
            *p = a[i];
        }
    }
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    cout<<ans.size()<<'\n';
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}