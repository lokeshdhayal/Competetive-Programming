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
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    int i = 0;
    int j = 0;
    vi b;
    int res = 0;
    while(j < n){
       // cout<<"ues";
        b.push_back(a[j]);
        if(j - i + 1 == k){
            sort(b.begin() , b.end());
            if(k%2 == 0){
                res = max(res,((b[k/2] + b[(k)/2 - 1])/2));
            }
            else{
                res = max(b[k/2] , res);
            }
            int loks = lower_bound(b.begin() , b.end() , a[i]) - b.begin();
            b.erase(b.begin() + loks);
            i++;
        }
        j++;
    }
    cout<<res<<nl;
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 