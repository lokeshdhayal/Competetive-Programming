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
ll n , t , m , temp , temp2 ,p , q ,  r , root;

ll gcd(ll a ,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b , a%b);
}

bool check(int mid , vector<pi> v){
    ll sum_val = 0;
    for(int i = 0;i < mid;i++){
        sum_val += v[i].first;
    }
    int i = mid;
   // cout<<sum_val<<'\n';
    while(i < n && sum_val >= v[i].first){
        sum_val += v[i].second;
        i++;
      //  cout<<sum_val<<'\n';
    }
    return (i == n);
}

void func(){
    cin>>n;
    vector<pi> v;
    ll sum_val = 0;
    for(int i = 0;i < n;i++){
        cin>>temp;
        sum_val += temp;
        v.push_back({temp , i + 1});
    }
    ll c = 1;
    sort(v.begin() , v.end());
    for(ll i = n - 2;i >= 0;i--){
        sum_val -= v[i + 1].first;
        if(sum_val < v[i + 1].first){
            break;
        }
        else{
            c++;
        }
    }
    vi v2;
    for(ll i = n - 1;i >= n - c;i--){
        v2.push_back(v[i].second);
    }
    sort(v2.begin() , v2.end());
    cout<<v2.size()<<'\n';
    for(int i = 0;i < v2.size();i++){
        cout<<v2[i]<<" ";
    }
    cout<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 