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
    pqmx p1;
    pqmn p2;
    while(n--){
        cin>>temp;
        if(pq1.empty() || pq1.top() > temp){
            pq1.push(temp);
        }
        else{
            pq2.push(temp);
        }
        if(pq1.size() > pq2.size() + 1){
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq2.size() > pq1.size() + 1){
            pq1.push(pq2.top());
            pq2.pop();
        }
        if(pq1.size() > pq2.size()){
            cout<<pq1.top()<<nl;
        }
        else if(pq1.size() < pq2.size()){
            cout<<pq2.top()<<nl;
        }
        else{
            cout<<((pq1.top() + pq2.top()) / 2)<<nl
        }
    }
}



int main(){
    t = 1;
    while(t--){
        func();
    }
} 