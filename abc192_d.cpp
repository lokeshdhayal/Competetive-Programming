#include<iostream>
#include <bits/stdc++.h>
#include<string.h>
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
ll n , t , m , temp , temp2 ,p , q ,  r , root , k;
bool flag = false;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll find_v(string s , ll p){
    ll val = 0;
    ll q = 0;
    for(int i = s.size() - 1;i >= 0;i--){
        val +=  (s[i] - '0')*binpow(p , q);
        if(val > k){
            flag = true;
            break;
        }
        q++; 
    }
    return val;
}

void func(){
    string s;
    cin>>s>>k;
    ll max_ = 0;
    vector<int> res;
    for(char i : s){
        res.push_back(i - '0');
        if(i - '0' > max_){
            max_ = i - '0';
        }
    }
    ll d = max_;
    if(res.size() == 1){
        if(d <= m){
            cout<<1;
        }
        else{
            cout<<0<<'\n';
        }
        return;
    }
    ll l = d + 1;
    ll r = LONG_MAX;
    while(l <= r){
        ll mid = (r - l) / 2 + l;
        flag = false;
        ll val = find_v(s , mid);
        cout<<mid<<" "<<val<<'\n';
        if(val <= k && val != 0){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<(r - d)<<'\n';
}



int main(){
    t = 1;
    while(t--){
    	func();
    }
} 