#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define nl "\n"
#define INF 1000

ll t,n,w1,w2,W,m,papu = 0,k,d,temp;
void func(){
	string s;
	cin>>n;
    cin>>s;
    ll low,high,mid;
    string res = "";
    for(int i = 0;i*4 < s.size();i++){
    	string temp = s.substr(i*4,(i + 1)*4);
    	low = 1;
    	//cout<<temp<<nl;
    	high = 16;
    	for(int j = 0;j < 4;j++){
    		mid = (low + high)/2;
    		if(temp[j] == '1'){
    			low = mid + 1;
    		}
    		else{
    			high = mid - 1;
    		}
    	}
    	//cout<<low<<" "<<high<<nl;
    	res += low - 1 + 'a';
    }
    cout<<res<<nl;
}

int main(){
    cin>>t;
    while(t--){
        func();
    }
}
