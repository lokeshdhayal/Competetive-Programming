#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;

int change(string s){
    if(s[1] == '2'){
        s[0] = '0';
        s[1] = '0';
    }
    if(s[6] == 'P'){

//    cout<<"YES"<<" ";
        return (60*(10*(s[0] - '0') + (s[1] - '0')) + (s[3] - '0')*10 + (s[4] - '0')) + 720;
    }
    return (60*(10*(s[0] - '0') + (s[1] - '0')) + (s[3] - '0')*10 + (s[4] - '0'));
}


bool check(string s , string r){
    int a = change(r.substr(0 , 8));
   // cout<<r.substr(0 , 8)<<" "<<a<<nl;
    int b = change(r.substr(9 , 8));
   // cout<<r.substr(9 , 8)<<" "<<b<<nl;
    int c = change(s);
   // cout<<s<<" "<<c<<nl;
    if(b < a){
        if(c <= b){
            c += 1400;
        }
        b += 1400;

    }
    if(a <= c && b >= c){
        return true;
    }
    return false;
}

void func(){
    string p;
//    cout<<"YS";
    getline(cin , p);
    while(p.size() == 0){
        getline(cin , p);
    }
 //   cout<<p<<nl;
    cin>>n;
    string res = "";
    for(int i = 0;i < n;i++){
        string r;
        getline(cin , r);
        while(r.size() == 0){
            getline(cin , r);
        }
        if(check(p , r)){
            res += '1';
        }
        else{
            res += '0';
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