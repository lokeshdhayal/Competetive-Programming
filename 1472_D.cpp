#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define pd push_back
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
    cin>>n;
    vi a(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a.begin() , a.end() , greater<ll>());
    ll alice = 0;
    ll bob = 0;
    bool flag = true;
    for(int i = 0;i < n;i++){
        if(flag){
            if(a[i]%2 == 0){
                alice += a[i];
            }
            flag = false;
        }
        else{
            if(a[i]%2 == 1){
                bob += a[i];
            }
            flag = true;
        }
    }
    if(alice > bob){
        cout<<"Alice"<<'\n';
    }
    else if(bob > alice){
        cout<<"Bob"<<'\n';
    }
    else{
        cout<<"Tie"<<'\n';
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 