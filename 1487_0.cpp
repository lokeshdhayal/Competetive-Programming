#include<iostream>
#include <bits/stdc++.h>
using namespace std;

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
    cin>>n;
    vector<int> a;
    int max_val = INT_MAX;
    for(int i = 0;i < n;i++){
        cin>>temp;
        if(temp < max_val){
            max_val = temp;
        }
        a.push_back(temp);
    }
    int res = 0;
    for(int i : a){
        if(i != max_val){
            res++;
        }
    }
    cout<<res<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 