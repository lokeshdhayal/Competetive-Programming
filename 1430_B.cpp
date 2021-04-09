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

ll find_v(ll temp_val ,ll k){
    
}

void func(){
    ll k;
    cin>>n>>k;
    vector<int> a;
    for(int i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin() , a.end());
    int j = a.size() - 1;
    ll res = a[j];
    j--;
    while(k > 0){
        res += a[j];
        j--;
        k--;
    }
    cout<<res<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 