#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
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
    ll res = 0;
    ll k;
    ll sum_val = 0;
    cin>>n>>k;
    for(ll i = 0; i < n;i++){
        cin>>temp;
        res += ceil((double)temp / k);
        sum_val += temp;
    }
    ll res2;
    res2 = (sum_val) / k;
    if(sum_val % k != 0){
        res2++;
    }
    cout<<res2<<" "<<res<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 