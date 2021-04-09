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

void func(){
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int res = 0;
    for(int i = 0;i < n - 1;i++){
        int min_val = min(a[i] , a[i + 1]);
        int max_val = max(a[i] , a[i + 1]);
        while((double)max_val / min_val > 2){
            min_val *= 2;
            res++;
        }
    }
    cout<<res<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 