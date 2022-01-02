#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;


int main(){
	string s1 , s2;
	int n;
	cin>>s1>>s2;
	cin>>n;
	string a[n];
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	queue<string> q;
	vector<bool> vis(n , 0);
	map<string , int> mp;
	for(int i = 0;i < n;i++){
		mp[a[i]] = i;
	}
	if(s1 == s2){
		cout<<s1<<'\n';
	}
	else{
		q.push(s1);
		vis[mp[s1]] = 1;
		vector<int> b(n , -1);
		while(!q.empty()){
			string front = q.front();
			q.pop();
			int lok = mp[front];
			for(int i = 0;i < front.size();i++){
				char p = front[i];
				for(int j = 0;j < 26;j++){
					front[i] = (char)(j + 'a');
					if(mp.find(front) != mp.end()){
						q.push(front);
						b[mp[front]] = lok;
						vis[mp[front]] = 1;
					}
					if(front == s2){
						int curr = mp[front];
						while(curr != -1){
							cout<<a[b[curr]]<<'\n';
							curr = mp[a[b[i]]];
						}
						cout<<s1<<'\n';
						return 0;
					}
				}
				front[i] = p;
			}
		}
		cout<<-1<<'\n';
	}
}
