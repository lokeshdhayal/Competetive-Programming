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
    cin>>m>>n;
    vector<vi> a(m , vi(n));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>a[i][j];
        }
    }
    int f = 1;
    for(int i = 0;i < m;i++){
        int f1 = f;
        for(int j = 0;j < n;j++){
            if(a[i][j] % 2 == f1){
                a[i][j]++;
            }
            if(f1 == 0){
                f1 = 1;
            }
            else{
                f1 = 0;
            }
        }
        if(f == 0){
            f = 1;
        }
        else{
            f = 0;
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<nl;
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 