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

void func(){
    ll k;
    cin>>n>>k;
    vi a;
    vi b;
    for(int i = 0;i < n;i++){
        cin>>temp;
        a.push_back(temp);
    }
    for(int i = 0;i < n;i++){
        cin>>temp;
        b.push_back(temp);
    }
    sort(a.begin() , a.end());
    sort(b.begin() , b.end());
    for(int i = 0,j = n - 1;i < a.size();i++,j--){
        if(!(a[i] + b[j] <= k)){
            cout<<"NO"<<nl;
            return;
        }
    }
    cout<<"YES"<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 