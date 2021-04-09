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
ll n , t , m , temp , temp2, root;

ll solve(int p , int b){
  /*  if(b%p == 0){
        return b;
    }*/
    int l = 1;
    ll res = LONG_MAX;
    int r = p;
    while(l <= r){
        ll mid = (r - l)/2 + l;
        if(mid * b * 1L >= p){
            res = min(mid , res);
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return b*res;
}

bool comp(pi a , pi b){
    if(a.first > b.first){
        return true;
    }
    return false;
}

void func(){
    cin>>n;
    vi a(n);
    vector<pi> b(n);
    for(int i = 0;i < n;i++){
        cin>>a[i];
        b[i] = { a[i] , i };
    }
    vi res;
    int q = n;
    sort(b.begin() , b.end() , comp);
    for(int i = 0;i < b.size();i++){
        if(b[i].second < q){
            int p = q;
            q = b[i].second;
            for(int j = q;j < p;j++){
                res.push_back(a[j]);
            }
        }
    }
    for(int i = 0;i < res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
}



int main(){
  //  cout<<solve(10 , 10);
    cin>>t;
    while(t--){
        func();
    }
} 