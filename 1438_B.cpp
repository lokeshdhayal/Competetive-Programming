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

void func(){
    cin>>n;
    map<int , int> hash;
    bool flag = false;
    for(int i = 0;i < n;i++){
        cin>>temp;
        if(hash[temp] == 1){
            flag = true;
        }
        else{
            hash[temp]++;
        }
    }
    if(flag){
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