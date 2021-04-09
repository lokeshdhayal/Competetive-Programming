#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,i,j,w1,w2,W,m,papu = 0,k,d,temp,x,y,p;
int a[1001];
int func1(){
    stack<pair<int,int> > st;
    vector<int> b,c;
    for(i = 0;i < n;i++){
        if(st.empty()){
            b.push_back(-1);
        }
        else if(st.top().first < a[i]){
            b.push_back(st.top().second);
        }
        else{
            while(!st.empty() && st.top().first >= a[i]){
                st.pop();
            }
            if(st.empty()){
                b.push_back(-1);
            }
            else{
                b.push_back(st.top().second);
            }
        }
        //cout<<i<<nl;
        st.push({a[i] , i});
    }
    while(!st.empty())st.pop();
    for(i = n-1;i >= 0;i--){
        if(st.empty()){
            c.push_back(n);
        }
        else if(st.top().first < a[i]){
            c.push_back(st.top().second);
        }
        else{
            while(!st.empty() && st.top().first >= a[i]){
                st.pop();
            }
            if(st.empty()){
                c.push_back(n);
            }
            else{
                c.push_back(st.top().second);
            }
        }
        //cout<<i<<nl;
        st.push({a[i] , i});
    }
    reverse(c.begin(),c.end());
    vector<int> width;
    for(i = 0;i < b.size();i++){
        width.push_back(c[i] - b[i] - 1);
        //cout<<width[i]<<" "<<b[i]<<" "<<c[i]<<nl;
    }
    int max1 = a[0]*width[0];
    for(i = 1;i < width.size();i++){
        if(max1 < a[i]*width[i]){
            max1 = a[i]*width[i];
        }
    }
    return max1;
}

void func(){
    cin>>m>>n;
    char hist[m][n];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin>>hist[i][j];
        }
    }
  //  cout<<"yes";
    int res = 0;
    memset(a , 0 , sizeof(a));
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(hist[i][j] == 'R'){
                a[j] = 0;
            }
            else{
                a[j] = a[j] + 1; 
            }
        }
     /*   cout<<"Array"<<nl;
        for(int i = 0;i < n;i++){
            cout<<a[i]<<" ";
        }
        cout<<nl;*/
        res = max(res , func1());
    }
    cout<<3*res<<nl;
}


int main(){
    cin>>t;
    while(t--){
        func();
    }
}
