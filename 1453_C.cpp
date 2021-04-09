#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
#define fr(i,n) for(i=0;i<n;i++)
#define rep(i,a,n) for(i=a;i<n;i++)
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<ll , ll> pi;
ll n , t , m , temp , temp2, root , p ,q , k , i , j;


void func(){
	int n;
	cin>>n;
	vector<string> s(n);
	for(int i = 0;i < n;i++){
		cin>>s[i];
	}
	vector<int> ans(10 , 0);
	vector<int> minrow(10 , n);
	vector<int> mincol(10 , n);
	vector<int> maxrow(10 , -1);
	vector<int> maxcol(10 , -1);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int num = s[i][j] - '0';
			minrow[num] = min(minrow[num] , i);
			mincol[num] = min(mincol[num] , j);
			maxcol[num] = max(maxcol[num] , j);
			maxrow[num] = max(maxrow[num] , i);
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int num = s[i][j] - '0';
			ans[num] = max(ans[num] , max(n - 1 - i , i) * max(maxcol[num] - j , j - mincol[num]));
			ans[num] = max(ans[num] , max(n - 1 - j , j) * max(maxrow[num] - i , i - minrow[num]));
		}
	}
	for(int i = 0;i < ans.size();i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}



int main(){
    cin>>t;
    while(t--){
        func();
    }
} 