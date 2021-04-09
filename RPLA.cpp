#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

bool comp(pi a , pi b){
    return (a.first > b.first);
}


void func(){
    cin>>n>>m;
    vi adj[n];
    vi ind(n , 0);
    for(int i = 0;i < m;i++){
        cin>>p>>q;
        adj[q].push_back(p);
        ind[p]++;
    }
    vector<pi> res;
    priority_queue<pi , vector<pi> , greater<pi> > pq;
    for(int i = 0;i < n;i++){
        if(ind[i] == 0){
            pq.push({ 1 , i });
        }
    }
    while(!pq.empty()){
        pi l = pq.top();
        res.push_back(l);
        pq.pop();
        for(ll i : adj[l.second]){
            ind[i]--;
            if(ind[i] == 0){
                pq.push({ l.first + 1 , i });
            }
        }
    }
    cout<<"Scenario #"<<k<<':'<<'\n';
    cout<<'\n';
    for(int i = 0;i < res.size();i++){
        cout<<res[i].first<<" "<<res[i].second<<'\n'<<'\n';
    }
}



int main(){
    cin>>t;
    while(t--){
        k++;
        func();
    }
} 