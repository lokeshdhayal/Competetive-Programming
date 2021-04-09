#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"


ll n , t , m , temp , temp2 , r , root;

bool is_valid(int i , int j ,vector<vector<char> > a){
    if(i < 0 || j < 0){
        return false;
    }
    if(i >= m || j >= n){
        return false;
    }
    if(a[i][j] == 'X'){
        return false;
    }
    return true;
}


void func(){
    vector<vector<char> > a(m , vector<char>(n));
    priority_queue<pair<int , pair<int , int>> ,vector<pair<int , pair<int , int> >> , greater<pair<int , pair<int , int> >>> pq;
    // , 
    int res1 , res2;
    vector<vector<int> >  res(m , vector<int>(n , INF));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>a[i][j];
            if(a[i][j] == 'S'){
                pq.push({0 , { i , j }});
                res[i][j] = 0;
            }
            if(a[i][j] == 'D'){
                res1 = i;
                res2 = j;
            }
        }
    }
    while(!pq.empty()){
        //cout<<pq.size()<<nl;
        int curr_d = pq.top().first;
        int i = pq.top().second.first;
        int j = pq.top().second.second;
     //  cout<<curr_d<<" "<<i<<" "<<j<<nl;
        pq.pop();
        int dx[] = { 1 , 0 , -1 , 0};
        int dy[] = { 0 , 1 , 0 , -1};
        for(int k = 0;k < 4;k++){
            if(is_valid(i + dx[k] , j + dy[k] , a)&& curr_d + a[i + dx[k]][j + dy[k]] - '0' <= res[i + dx[k]][j + dy[k]]){
                if(a[i + dx[k]][j + dy[k]] == 'D'){
                    cout<<curr_d<<nl;
                    cin>>n>>m;
                    return;
                }
                res[i + dx[k]][j + dy[k]] = curr_d + a[i + dx[k]][j + dy[k]] - '0';
                //cout<<a[i + dx[k]]
                pq.push({curr_d + a[i + dx[k]][j + dy[k]] - '0', {i + dx[k] , j + dy[k]}});
            }
        }
    }
//    cin>>n>>m;
}

int main(){
    cin>>n>>m;
    while(m != 0 && n != 0){
        func();
    }
} 