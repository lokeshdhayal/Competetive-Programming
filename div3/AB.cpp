#include<iostream>
#include <bits/stdc++.h>
#include<stdio.h>
#include <string.h>
using namespace std;


struct Node{
    int mx;
    int mn;
    Node(){
    	mx = INT_MIN;
    	mn = INT_MAX;
    }
};
 
int a[1000];
 
Node S[4* 600010];
 
void Merge(Node & a , Node & b , Node & p){
    p.mx = max(a.mx , b.mx);
    p.mn = min(a.mn , b.mn);
}
 
void build(int si,int ss,int se){
    if(ss == se){
    	S[si].mx = a[ss];
    	S[si].mn = a[ss];
    }
    else{
        int mid = (se + ss)/2;
        build(2*si , ss , mid);
        build(2*si + 1,mid+1,se);
        Merge(S[2*si] , S[2*si + 1] , S[si]);
    }
}
 
Node query(int l,int r , int si,int ss,int se){
    if(ss > r || se < l){
        return Node();
    }
    if(ss >= l && se <= r)return S[si];
    int mid = (ss + se)/2;

    Node left = query(l,r,2*si , ss , mid);
    Node right = query(l,r,2*si + 1,mid+1,se);
    Node p;
    Merge(left , right , p);
    return p;
}
 
void Update(int l, int r , int si , int ss,int se,int val){
    if(ss > r || se < l){
        return;
    }
    if(ss >= l && se <= r){
        S[si].mx = val;
        S[si].mn = val;
    }
    else{
        int mid = (se + ss)/2;
        Update(l,r,2*si , ss , mid , val);
        Update(l,r,2*si + 1,mid+1,se , val);
        Merge(S[2*si] , S[2*si + 1] , S[si]);
    }
}
 


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0;i < n;i++){
			cin>>a[i];
		}
		build(1,0,n-1);
		map<int , vector<int> > mp;
		for(int i = n - 1;i >= 0;i--){
			mp[a[i]].push_back(i);
		}
		bool flag = 1;
		int curr = 0;
		for(auto & i : mp){
			while(!i.second.empty()){
				Node p = query(i.second.back() , i.second.back() , 1 , 0 , n - 1);
				if(i.second.back()<=curr){
					curr++;
					i.second.pop_back();
					continue;
				}
				else{
					Node p = query(curr , i.second.back() - 1, 1 , 0 , n - 1);
					if(p.mx == p.mn && p.mx == i.first+1){
						Update(i.second.back() , i.second.back() , 1 , 0 , n - 1 , i.first + 1);
					}
					else{
						flag = 0;
						break;
					}
				}
				i.second.pop_back();
				curr++;
			}
			if(flag == 0)break;
		}
		if(flag){
			cout<<"Yes"<<'\n';
		}
		else{
			cout<<"No"<<'\n';
		}
	}
}