#include<iostream>
#include <bits/stdc++.h>
#include<string.h>
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

int convert(int n){
    string p = to_string(n);
    string q = to_string(n);
    sort(p.begin() , p.end());
    sort(q.begin() , q.end() , greater<char>());
    return stoi(q) - stoi(p);
}

void func(){
    ll n , k;
    cin>>n>>k;
    while(k--){
        n = convert(n);
    }
    cout<<n<<'\n';
}



int main(){
    t = 1;
    while(t--){
    	func();
    }
} 