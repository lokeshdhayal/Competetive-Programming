#include<iostream>
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp> 
using namespace boost::multiprecision;
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;

ll n , t , m , temp , temp2 ,p , q ,s ,  r , root;

int1024_t s;
string res;



void func(){
    if(s == 0){
        cout<<0<<nl;
        return;
    }
    if(s == 1){
        cout<<1<<nl;
    }
    s = s - 1;
    s /= 2;
    cout<<s<<nl;
}



int main(){
    while(cin>>s){
        func();
    }
} 