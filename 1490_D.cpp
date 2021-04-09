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

void solve(int i , int j , vector<int> & res , int a[] ,int height){
    if(i > j){
        return;
    }
    int max_val = -1;
    int max_idx;
    for(int k = i; k <= j;k++){
        if(a[k] > max_val){
            max_val = a[k];
            max_idx = k;
        }
    }
    res[max_idx] = height + 1;
    solve(i , max_idx - 1 , res , a , height + 1);
    solve(max_idx + 1 , j , res , a , height + 1);
}

void func(){
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    vector<int> res(n);
    solve(0 , n - 1 , res , a , -1);
    for(int i = 0; i < res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 