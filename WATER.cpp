#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define ld double
typedef vector<int> vi;
typedef vector<bool> vb;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;



bool is_valid(int i , int j ,vector<vector<bool> > & vis){
        if(i < 0 || j < 0){
            return false;
        }
        if(i >= vis.size() || j >= vis[0].size()){
            return false;
        }
        if(vis[i][j] == true){
            return false;
        }
        return true;
}
    
    
int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int , pair<int , int> > , vector<pair<int , pair<int , int> >> , greater<pair<int , pair<int , int> > > > pq;
vector<vector<bool> > vis(heightMap.size() ,vector<bool>(heightMap[0].size(),false));
        
        for(int i = 0;i < heightMap[0].size();i++){
            vis[0][i] = true;
            vis[heightMap.size() - 1][i] = true;
            pq.push({ heightMap[0][i] , { 0 , i }});
            pq.push({ heightMap[heightMap.size() - 1][i] , { heightMap.size() - 1 , i }});
        }
        for(int i = 0;i < heightMap.size();i++){
            vis[i][0] = true;
            vis[i][heightMap[0].size() - 1] = true;
            pq.push({ heightMap[i][0] , { i , 0 }});
            pq.push({ heightMap[i][heightMap[0].size() - 1],{i,heightMap[0].size()-1 }});
        }
        int res = 0;
        int max_val = INT_MIN;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            max_val = max(max_val , p.first);
            int dx[] = {1 , 0 , -1 , 0};
            int dy[] = {0 , 1 , 0 , -1};
            int i = p.second.first;
            int j = p.second.second;
         //   cout<<p.first<<" "<<i<<" "<<j<<" "<<max_val<<" "<<res<<'\n';
            for(int k = 0;k < 4;k++){
                if(is_valid(i + dx[k] , j + dy[k] , vis)){
                    if(heightMap[i + dx[k]][j + dy[k]] < max_val){
                        res += max_val - heightMap[i + dx[k]][j + dy[k]];
                    }
                    vis[i + dx[k]][j + dy[k]] = true;
                    pq.push({ heightMap[i + dx[k]][j + dy[k]] ,{i + dx[k] ,j+dy[k]}});
                }
            }
            
        }
        return res;
}





void func(){
    cin>>n>>m;
    vector<vi> dp(n , vi(m));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin>>dp[i][j];
        }
    }
    cout<<trapRainWater(dp)<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
}