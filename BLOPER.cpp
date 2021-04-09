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
#define pd push_back
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;
string res;
bool flag = false;


void find_v(int i , int  k, int p,string s){
    if(p - 1 == n && k == i){
        res = s;
        flag = true;
    }
    if(p != n && flag == false){
        find_v(i + p , k - p , p + 1 ,s + '+' + to_string(p));
        if(flag == false){
            find_v(i - p , k - p , p + 1 ,s + '-' + to_string(p) );
        }
    }
}

void func(){
    ll k;
    cin>>n>>k;
    if(k < 0){
        ll total = n * (n + 1) / 2;
        total--;
        if(abs(k) > total){
            cout<<"Impossible";
            return;
        }
        if((total - abs(k) + 1)%2 != 0){
            cout<<"Impossible";
            return;
        }  
        ll need = (total - abs(k) + 1) / 2 + abs(k);
       // cout<<need<<'\n';
        vector<int> vis(n + 1, 0);
        int p = n;
        while(p >= 2){
            if(need - p >= 0 && (need - p) != 1){
                vis[p] = 1;
                need -= p;
            }
            p--;
        }
        string res = "";
        res += '1'; 
        for(int i = 2;i <= n;i++){
            res += (vis[i] == 1) ? to_string(-i) :("+" + to_string(i)); 
        }
        cout<<res<<'\n';
        return;
    }
    k--;
    ll total = n * (n + 1) / 2;
    total--;
    if(k > total){
        cout<<"Impossible";
        return;
    }
    if((total - k)%2 != 0){
        cout<<"Impossible";
        return;
    }
    vector<int> vis(n + 1, 0);
    int p = n;
    ll need = k + (total - k)/2;
    need = total - need;
    while(p >= 2){
        if(need - p >= 0){
            vis[p] = 1;
            need -= p;
        }
        p--;
    }
    string res = "";
    res += '1'; 
    for(int i = 2;i <= n;i++){
        res += (vis[i] == 1) ? to_string(-i) :("+" + to_string(i)); 
    }
    cout<<res<<'\n';
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 