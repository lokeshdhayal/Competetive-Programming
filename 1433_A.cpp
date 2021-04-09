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
    string s;
    cin>>s;
    ll res = (s[0] - '0' - 1)*10;
    if(s.size() == 1){
        cout<<(res + 1)<<nl;
        return;
    }
    if(s.size() == 2){
        cout<<(res + 3)<<nl;
        return;
    }
    if(s.size() == 3){
        cout<<(res + 6)<<nl;
        return;
    }
    cout<<(res + 10)<<nl;

}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 