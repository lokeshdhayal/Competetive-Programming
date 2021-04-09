#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://o...content-available-to-author-only...s.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

bool comp(pi a , pi b){
    return (a.first > b.first);
}


void func(){
    cin>>n;
    vi a(n);
    ll res = 0;
    bool flag = true;
    for(int i = 0;i < n;i++){
        cin>>temp;
        temp -= res;
        if(temp < 0){
            flag = false;
        }
        res = temp;
    }
    if(res == 0 && flag){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 