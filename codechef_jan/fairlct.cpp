#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,i,j,w1,w2,W,m,papu = 0,k,d,temp;
int a[1005],b[1005];
void func(){
    cin>>m>>n;
    ll sum1 = 0,sum2 = 0;
    for(i = 0;i < m;i++)cin>>a[i],sum1 += a[i];
    for(j = 0;j < n;j++)cin>>b[j],sum2 += b[j];
    if(sum1 > sum2){
        cout<<0<<nl;
        return;
    }
    sort(a,a + m);
    sort(b,b + n);
    i = 0;
    int counter = 0;
    j = n-1;
    while(i < m && j >= 0){
        counter++;
        sum1 += b[j];
        sum1 -= a[i];
        sum2 += a[i];
        sum2 -= b[j];
        i++;
        j--;
        if(sum1 > sum2){
            cout<<counter<<nl;
            return;
        }
    }
    cout<<-1<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
