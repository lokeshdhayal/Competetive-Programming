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
typedef pair<int , int> pi;

void input(vi & a , int n){
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
}

ll n , t , m , temp , temp2 ,p , q ,  r , root , k;

void func(){
    cin>>n;
    vi a(n);
    vi b(n);
    vi c(n);
    vi d(n);
    for(int i = 0;i < n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    vi p;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            p.push_back(a[i] + b[j]);
        }
    }
    ll res = 0;
    sort(p.begin() , p.end());
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ll q = -c[i] - d[j];
            auto lok = equal_range(p.begin() , p.end() , q);
            res += lok.second - lok.first;
        }
    }
    cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 