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
ll n , t , m , temp , temp2 ,p , q ,  r , root;

ll find_v(ll temp_val ,ll k){
    
}

void func(){
    ll k;
    cin>>n>>k;
    ll res = 0;
    bool flag = true;
    for(int i = 0;i < n;i++){
        cin>>temp;
        ll res1 = 0;
        if(flag){
            res1 += temp;
            int l = 2;
            while(temp % k == 0){
                res1 += (temp / k)*l;
                l *= 2;
                temp /= k;
            }
            if(temp != 0){
                flag = false;
            }
        }
        else{
            res1 = temp;
        }
        res += res1;
    }
    cout<<res<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 