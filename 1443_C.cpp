#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;

bool comp(vi a , vi b){
    if(a[0] < b[0]){
        return true;
    }
    return false;
}

void func(){
    ll k;
    cin>>n;
    vector<vi>  a(n , vi(2));
    //vi b;
    ll sum_val = 0;
    for(int i = 0;i < n;i++){
        cin>>a[i][0];
    }
    for(int i = 0;i < n;i++){
        cin>>a[i][1];
        sum_val += a[i][1];
    }
    sort(a.begin() , a.end() , comp);
    ll res1  = sum_val;
    ll res2 = INT_MAX;
    for(int i = 0;i < a.size();i++){
        sum_val -= a[i][1];
        res2 = min(res2 , max(sum_val , a[i][0]));
    //    cout<<sum_val<<" "<<a[i][0]<<nl;
    }
    cout<<min(res1 , res2)<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 