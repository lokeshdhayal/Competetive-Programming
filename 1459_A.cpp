#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<int> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
ll n , t , m , temp , temp2 ,p , q ,  r , root;

void func(){
    cin>>temp;
    string s1 , s2;
    cin>>s1>>s2;
    int count1 = 0;
    for(int i = 0;i < s1.size();i++){
        if(s1[i] > s2[i]){
            count1++;
        }
        else if(s1[i] < s2[i]){
            count1--;
        }
    }
    if(count1 > 0){
        cout<<"RED"<<nl;
    }
    else if(count1 < 0){
        cout<<"BLUE"<<nl;
    }
    else{
        cout<<"EQUAL"<<nl;
    }
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 