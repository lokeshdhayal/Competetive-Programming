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
typedef pair<int , int> pi;
ll n , t , m , temp , temp2 ,p , q ,  r , root , k;

void func(){
    cin>>n>>k;
    if(n % k == 0){
        cout<<1<<'\n';
        return;
    }
    if(n > k){
        cout<<2<<'\n';
        return;
    }
    if(k % n == 0){
        cout<<(k / n)<<'\n';
        return;
    }
    cout<<((k / n) + 1)<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 