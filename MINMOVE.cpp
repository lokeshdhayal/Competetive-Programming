#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2 , p , q , r , root;

int find_v(string s){
    s += s;
    int i = 0;
    int n = s.size();
    int j , k ;
    int ans = 0;
    while(i < n / 2){
        ans = i;
        j = i + 1;
        k = i;
        while(j < n && s[k] <= s[j]){
            if(s[k] < s[j]){
                k = i;
            }
            else{
                k++;
            }
            j++;
        }
        while(i <= k){
            i += j - k;
        }
    }
    return ans;
}

void func(){
    string s;
    cin>>s;
    cout<<(find_v(s) + 1)<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 