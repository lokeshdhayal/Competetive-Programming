#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
ll p,q,n,minimum,max1,temp,x,t,m,k,count1,result;

ll a,b,c,d,sum;

ll min(ll a,ll b){
    if(a > b){
        return b;
    }
    return a;
}

void func(){
    cin>>sum;
    cin>>a>>b>>c>>d;
    result = 0;
    for(int i = min(d , sum / 10);i >= 0;i--){
        for(int j = min(c , (sum - i * 10) / 5);j >= 0;j--){
            for(int k = min(b , (sum - i * 10 - j *5) / 2);k >= 0;k--){
                for(int l = min(a , sum - i * 10 - j * 5 - k * 2);l >= 0;l--){
                    if(10 * i + 5 * j + 2 * k + l == sum){
                        result++;
                     //   cout<<i<<" "<<j<<" "<<k<<" "<<" "<<l<<nl;
                        break;
                    }
                }
            }
        }
    }
    cout<<result<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
