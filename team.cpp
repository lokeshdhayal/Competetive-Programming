#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"
//ll p,q , r , x = 0;
ll n , t , m , temp , temp2;
struct TreeNode{
    bool we;
    TreeNode * child[26];
};

TreeNode * root;

TreeNode * getNode(){
    TreeNode *newNode = new TreeNode();
    newNode->we = false;
    for(int i = 0;i < 26;i++){
        newNode->child[i] = NULL;
    }
    return newNode;
}

void insert(string s){
    TreeNode * curr;
    curr = root;
    for(int i = 0;i < s.size();i++){
        int k = s[i] - 'a';
        if(!curr->child[k]){
            curr->child[k] = getNode();
        }
        curr = curr->child[k];
    }
    curr->we = true;
}

bool search(string s){
    TreeNode * curr;
    curr = root;
    for(int i = 0;i < s.size();i++){
        int k = s[i] - 'a';
        if(!curr->child[k]){
            return false;
        }
        curr = curr->child[k];
    }
    return (curr != NULL && curr->we);
}


void func(){
    root = getNode();
    insert("mas");
    insert("suf");
    vector<string> a;
    cin>>n;
    for(int i = 0;i < n;i++){
        string s;
        cin>>s;
        a.push_back(s);
        insert(s);
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            if(a[i][0] == a[j][0]){
                continue;
            }
            char k = a[i][0];
            char l = a[j][0];
            a[i][0] = l;
            a[j][0] = k;
            //cout<<a[i]<<" "<<a[j]<<nl;
            if(!search(a[i]) && !search(a[j])){
                res++;
            }
            a[i][0] = k;
            a[j][0] = l;
        }
    }
    cout<<2*res<<nl;
}

int main(){
    cin>>t;
   // cout<<change("11:43 PM");
    while(t--){
        func();
    }
} 