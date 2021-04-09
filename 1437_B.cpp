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
    cin>>temp;
    string s;
    cin>>s;
    int count_0 = 0;
    int count_1 = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '0'){
            continue;
        }
        int p = 0;
        while(s[i] == '1'){
            p++;
            i++;
        }
        count_1 += p - 1;
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] == '1'){
            continue;
        }
        int p = 0;
        while(s[i] == '0'){
            p++;
            i++;
        }
        count_0 += p - 1;
    }
    cout<<max(count_1 , count_0)<<nl;
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 