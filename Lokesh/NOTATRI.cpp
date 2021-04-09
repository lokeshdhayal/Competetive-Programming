#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
unsigned ll p,q;
ll n , k , t,m ;

unsigned ll find_p(unsigned ll p){
    if(p % 2 == 0){
        p /= 2;
    }
    else{
        p = (p + 1) / 2;
    }
    return p*p;
}

int binary_search(int a[], int i , int j , int val){
    int p = i;
    int ans = 0;
   // cout<<val<<nl;
    while(i <= j){
        int mid = (i + j) / 2;
        if(a[mid] < val){
            ans = max(ans , mid + 1);
          //  cout<<"Hello";
            i = mid + 1;
        }
        else{
            j = mid - 1;
        }
    }
    return ans;
}


void func(){
    int a[n];
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    if(n < 3){
        cout<<"0"<<nl;
        return;
    }
    sort(a , a + n);
    int count = 0;
    int i = n - 1, j = n - 1;
    while(i >= 2){
        j = i - 1;
        while(j >= 1){
            count += binary_search(a , 0 , j - 1 ,  a[i] - a[j]);
        //    cout<<count<<" "<<j<<" "<<i<<nl;
            j--;
        }
      //  cout<<i<<" "<<j<<nl;
        i--;
    }
    cout<<count<<nl;
    cin>>n;
}

int main(){
    cin>>n;
    while(n != 0){
        func();
    }
}