#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
#define N 40000;
ll T = 40000*4;
ll n , t , m , temp , temp2 ,p , q ,  r , root;


string s;

vector< vector<int> > a(T , vector<int>(2));

void init(int idx , int i , int j){
    if(i == j){
        a[idx][0] = a[idx][1] = (s[i] == '(') ? 1 : -1 ;
        return;
    }
    int mid = (i + j) / 2;
    init(2*idx , i , mid);
    init(2*idx + 1 , mid + 1 , j);
    a[idx][0] = a[2*idx][0] + a[2*idx + 1][0];
    a[idx][1] = min(a[2*idx][1] , a[2*idx][0] + a[2*idx + 1][1]);
}


void update(int idx , int i , int j , int k){
    if(i == j){
        a[idx][0] = a[idx][1] = -a[idx][0];
        return;
    }
    int mid = (i + j) / 2;
    if(k <= mid)
         update(2*idx , i , mid , k);
    else
        update(2*idx + 1 , mid + 1 , j , k);
    a[idx][0] = a[2*idx][0] + a[2*idx + 1][0];
    a[idx][1] = min(a[2*idx][1] , a[2*idx][0] + a[2*idx + 1][1]);
}




int main(){
    p = 0;
    while(cin>>n){
        cin>>s;
        p++;
        cout<<"Test "<<p<<":"<<nl;
        init(1 , 0 , s.size() - 1);
        /*for(int i = 0;i < 10;i++){
            cout<<a[i][0]<<" "<<a[i][1]<<nl;
        }*/
        cin>>t;
        while(t--){
            cin>>n;
            if(n == 0){
                if(a[1][0] == 0 && a[1][1] == 0){
                    cout<<"YES"<<nl;
                }
                else{
                    cout<<"NO"<<nl;
                }
            }
            else{
                update(1 , 0 , s.size() - 1 , n - 1);
            }
        }
    }
} 