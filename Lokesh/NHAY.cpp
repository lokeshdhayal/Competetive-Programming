#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,x,t,m,k,count1,result;

ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }
    return gcd(b,a%b);
}

vector<int> prefix(string s){
    vector<int> temp(s.size() , 0);
    for(int i = 1;i < s.size();i++){
        int j = temp[i -  1];
        while(j > 0 && s[i] != s[j]){
            j = temp[j  - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        temp[i] = j;
    }
    return temp;
}


void func(){
    vector<int> a;
    string p,t;
    cin>>p;
    cin>>t;
 //   cout<<"yy";
    a = prefix(p);
    int i = 0,j = 0;
    bool flag = false;
    while(i < t.size()){
        if(t[i] == p[j])
            i++,j++;
        if(j == p.size()){
            cout<<(i - j)<<nl;
            j = a[j - 1];
            flag = true;
        }
        else if(i < t.size() && t[i] != p[j]){
            if(j > 0){
                j = a[j - 1];
            }
            else{
                i++;
            }
        }
    }
    if(!flag){
        cout<<nl;
    }
}

int main(){
    while(cin>>n){
        func();
    }
}