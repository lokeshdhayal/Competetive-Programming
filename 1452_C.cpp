#include<iostream>
#include <bits/stdc++.h>
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

void func(){
    string s;
    cin>>s;
    int count_val  = 0;
    int p = 0;
    for(char i : s){
        if(i == '('){
            count_val++;
        }
        else if(i == ')'){
            if(count_val > 0){
                count_val--;
                p++;
            }
        }
    }
    count_val = 0;
  //  cout<<'\n';
    for(char i : s){
        if(i == '['){
            count_val++;
        }
        else if(i == ']'){
            if(count_val > 0){
                count_val--;
                p++;
            }
        }
    }
    cout<<p<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 