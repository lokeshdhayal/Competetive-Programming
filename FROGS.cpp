#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;
int w[4];

bool comp(vector<int> a,vector<int> b){
    if(w[a[1] - 1] < w[b[1] - 1]){
        return true;
    }
    return false;
}


void func(){
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>w[i];
      //  w4[i] = w[i];
    }
    vector<vector<int> > dis;
    for(int i = 0;i < n;i++){
        vector<int> temp(2);
        cin>>temp[0];
        dis.push_back(temp);
    }
    for(int  i = 0;i < n;i++){
        dis[i][1] = i + 1;
    }
    int count1 = 0;
    sort(dis.begin(), dis.end(), comp);
    for(int i = 0;i < n;i++){
        cout<<dis[i][0]<<" "<<dis[i][1]<<nl;
    }
    for(int i = 1;i < n;i++){
        while(dis[i][1] <= dis[i - 1][1]){
            dis[i][1] += dis[i][0];
            count1++;
        }
    }
    cout<<count1<<nl;
}

int main(){
    cin>>t;
   // cout<<change("11:43 PM");
    while(t--){
        func();
    }
} 