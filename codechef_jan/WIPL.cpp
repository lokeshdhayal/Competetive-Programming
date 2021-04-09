#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,i,j,w1,w2,W,m,papu = 0,k,d,temp,x,y;

int a[4005];

void func(){
    cin>>n>>k;
    int mike = k,tracy = k;
    for(i = 0;i < n;i++)
        cin>>a[i];
    sort(a,a + n,greater<int>() );
    int counter = 0;
    i = 0;
    while(mike > 0 && tracy > 0 && i < n){
        mike -= a[i++];
        counter++;
        while(i < n && (mike - tracy) < a[i] && mike > 0){
            mike -= a[i++];
            counter++;
        }
        while(i < n && (mike - tracy) > a[i] && tracy > 0){
            tracy -= a[i++];
            counter++;
        }
       // cout<<"YES";
    }
    while(mike > 0 && i < n){
        mike -= a[i++];
        counter++;
    }
    while(tracy > 0 && i < n){
        tracy -= a[i++];
        counter++;
    }
    if(tracy <= 0 && mike <= 0){
        cout<<counter<<nl;
        return;
    }
    cout<<-1<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
