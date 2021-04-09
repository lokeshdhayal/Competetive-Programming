#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
ll n , t , m , k;

bool check(ll mid , vi a){
    ll p = 0;
    ll sum_val = 0;
    for(int i = 0;i < a.size();){
        while(i < a.size() && sum_val + a[i] <= mid){
            sum_val += a[i];
            i++;
        }
        sum_val = 0;
        p++;
        if(p > k){
            return false;
        }
    }
    return (p <= k);
}


void func(){
    cin>>n>>k;
    vi a(n);
    ll sum_val = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        sum_val += a[i];
    }
    int l = 0;
    ll res = LONG_MAX;
    int r = sum_val;
    while(l <= r){
        ll mid = (r - l) / 2 + l;
        if(check(mid , a )){
            res = min(res , mid);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    string result = "";
    sum_val = 0;
    k--;
    int i = n - 1;
    while(i >= 0){
        while(i >= 0 && sum_val + a[i] <= res && i >= k){
            sum_val += a[i];
            string q = to_string(a[i]) + " ";
            reverse(q.begin() , q.end());
            result += q;
            i--;
        }
        k--;
        result += " /";
        sum_val = 0;
    }
    reverse(result.begin() , result.end());
    result = result.substr(2);
    cout<<result<<'\n';
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}