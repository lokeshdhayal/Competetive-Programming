#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2 ,p , q ,  r , root;


void Hashkey(string & s,vector<string> & res){
    int k = 0;
    int p = 0;
    while(k < s.size()){
        p = (p + (k + 1)*(int)s[k]);
      //  cout<<p<<" ";
        k++;
    }
    p = (p * 19) % 101;
    ll lok = p;
    if(res[p] == s){
        return;
    }
    else{
        for(int i = 1;i <= 19;i++){
            p = (lok + i * i + 23 * i)%101;
            if(res[p] == s){
                return;
            }
        }
    }
    p = lok;
    if(res[p] == ""){
        res[p] = s;
    }
    else{
        for(int i = 1;i <= 19;i++){
            p = (lok + i * i + 23 * i)%101;
            if(res[p] == ""){
                res[p] = s;
                return;
            }
        }
    }
}


void func(){
    cin>>n;
    vector<string> res(101 , "");
    while(n--){
        string s;
        cin>>s;
        string p;
        string q = s.substr(0,  3);
        s = s.substr(4);
        if(q == "ADD"){
            Hashkey(s , res);
        }
        else if(q == "DEL"){
            for(int i = 0;i < 101;i++){
                if(res[i] == s){
                    res[i] = "";
                }
            }
        }
    }
    int count_val = 0;
    for(int i = 0;i < 101;i++){
        if(res[i] != ""){
            count_val++;
        }
    }
    cout<<count_val<<'\n';
    for(int i = 0;i < 101;i++){
        if(res[i] != ""){
            cout<<i<<":"<<res[i]<<'\n';
        }
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 