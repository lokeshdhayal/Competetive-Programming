#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;

ll find1(int n ,int m){
    ll res = 0;
    if(n < m){
        return 1;
    }
    while(n > m){
        if(m%3 != 0){
            m++;
            res++;
        }
        else{
            n /= m;
            res++;
        }
    }

    if(n == m){
        return res + 2;
    }
    return res + 1;
}
ll find2(int n ,int m){
    ll res = 0;
    if(m == 1){
        m++;
        res++;
    }
    while(n > m){
        n /= m;
        res++;
    }

    if(n == m){
        return res + 2;
    }
    return res + 1;
}

void func(){
    cin>>n>>m;
    int res = 0;
    cout<<min(find1(n , m) , find2(n , m))<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 