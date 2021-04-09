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

ll gcd(ll a ,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b , a%b);
}

bool is_valid(){
    for(ll i = 1;i*i*i < n;i++){
        double lok = cbrt(n - i*i*i);
    //    cout<<(ll)lok<<" "<<lok<<" "<<i<<nl;
        if((ll)lok == lok){
            return true;
        }
    }
    return false;
}

void func(){
    cin>>n;
    if(is_valid()){
        cout<<"YES"<<nl;
    }
    else{
        cout<<"NO"<<nl;
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 