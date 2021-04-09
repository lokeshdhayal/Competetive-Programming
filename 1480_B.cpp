#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"

typedef vector<ll> vi;

ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;


void func(){
    cin>>p>>q>>n;
    vector<pair<int , int> > a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i].first;
    }
    for(int i = 0;i < n;i++){
        cin>>a[i].second;
    }
    bool flag = false;
    sort(a.begin() , a.end());
    for(int i = 0;i < n;i++){
        ll r = ceil(1.0 * a[i].second / p);
        q -= r * a[i].first;
        if(a[i].first + q < 1){
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<"NO"<<'\n';
    }
    else{
        cout<<"YES"<<'\n';
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 