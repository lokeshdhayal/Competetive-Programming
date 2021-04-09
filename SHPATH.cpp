#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 , r , root , p , q;

int find_v(int s , int d , vector<pair<int , int> > adj[]){
    priority_queue<pair<int , int> ,vector<pair<int , int> > , greater<pair<int , int> >> pq;
    vector<int> dis(n + 1 , INF);
    pq.push({0 , s});
    dis[s] = 0;
    while(!pq.empty()){
        int curr = pq.top().second;
        int curr_d = pq.top().first;
        pq.pop();
        if(curr == d){
            return curr_d;
        }
      //  cout<<curr<<" "<<curr_d<<nl;
        for(auto i : adj[curr]){
            if(i.second + curr_d <= dis[i.first]){
                dis[i.first] = i.second + curr_d; 
                pq.push({dis[i.first] , i.first });
            }
        }
    }
    return dis[d];
}

void func(){
    cin>>n;
    vector<pair<int , int> > adj[n + 1];
    map<string , int> hash;
    for(int i = 1;i <= n;i++){
        string s;
        cin>>s;
        hash[s] = i;
        cin>>r;
        while(r--){
            cin>>p>>q;
            adj[i].push_back({p , q});
        }
    }
    
    //cout<<"yes"<<nl;
    cin>>r;
    string r1 , r2;
    while(r--){
        cin>>r1>>r2;
        cout<<find_v(hash[r1] , hash[r2] , adj)<<nl;
    }
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
} 