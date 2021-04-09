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


void func(){
    cin>>n>>m;
    string p;
    string q;
    cin>>p>>q;
    int j = 0;
    vi a;
    vi b;
    for(int i = 0;i < p.size();i++){
        if(j < p.size() && p[i] == q[j]){
            j++;
            a.push_back(i);
        }
    }
    j = q.size() - 1;
    for(int i = p.size() - 1;i >= 0;i--){
        if(j >= 0 && p[i] == q[j]){
            j--;
            b.push_back(i);
        }
    }
    reverse(b.begin() , b.end());
    ll max_val = 0;
    for(int i = 0;i < m - 1;i++){
        max_val = max(max_val , b[i + 1] - a[i]);
    }
    cout<<max_val<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 