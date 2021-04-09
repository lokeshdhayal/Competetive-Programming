#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

void func(){
    cin>>n;
    vector<string> a;
    set<string> p;
    for(int i = 0;i < n;i++){
        string s;
        cin>>s;
        a.push_back(s);
        p.insert(s);
    }
    int res = 0;
    for(int i = 0;i < a.size();i++){
        for(int j = 0;j < a.size();j++){
            if(i == j){
                continue;
            }
            char k = a[i][0];
            char l = a[j][0];
            a[i][0] = l;
            a[j][0] = k;
           // cout<<a[i]<<" "<<a[j]<<nl;
            if(p.find(a[i]) == p.end() && p.find(a[j]) == p.end()){
                res++;
            }
            a[i][0] = k;
            a[j][0] = l;
            //cout<<a[i]<<" "<<a[j]<<nl;
        }
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
   // cout<<change("11:43 PM");
    while(t--){
        func();
    }
} 