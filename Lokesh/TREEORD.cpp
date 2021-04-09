#include<iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define MAX 1000000
#define nl "\n"

ll p,q;
int inorder[8001] , preorder[8001] , postorder[8001];
ll n , k , t;
map<int , int> hashmap;

class TreeNode {
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int d) {
            val = d;
            left = NULL;
            right = NULL;
        }
};

TreeNode * buildLeft(int i , int j){
    if(i > j){
        return NULL;
    }
    TreeNode * root;
    root  = new TreeNode(preorder[k++]);
    if(i == j){
        return root;
    }
    root->left = buildLeft(i , hashmap[root->val] - 1);
    root->right = buildLeft(hashmap[root->val] + 1,j);
    return root;
}

TreeNode * buildRight(int i , int j){
    if(i > j){
        return NULL;
    }
    TreeNode * root;
    root = new TreeNode(postorder[k--]);
    if(i == j){
        return root;
    }
    root->right = buildRight(hashmap[root->val] + 1,j);
    root->left = buildRight(i , hashmap[root->val] - 1);
    return root;
}

bool check(TreeNode * p,TreeNode * q){
    if(p == NULL && q == NULL){
        return true;
    }
    if(p == NULL || q == NULL){
        return false;
    }
    if(p->val != q->val){
        return false;
    }
    return check(p->left , q->left) && check(p->right , q->right); 
}

void pre(TreeNode * root){
    if(root != NULL){
        pre(root->left);
        cout<<root->val<<" ";
        pre(root->right);
    }
}

void func(){
    cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>preorder[i];
    }
    for(int i = 1;i <= n;i++){
        cin>>postorder[i];
    }
    for(int i = 1;i <= n;i++){
        cin>>inorder[i];
    }
    for(int i = 1;i <= n;i++){
        hashmap[inorder[i]] = i;
    }
    TreeNode *leftTree;
    TreeNode *rightTree;
    k = 1;
    leftTree = buildLeft(1 , n);
    k = n;
    rightTree = buildRight(1 , n);
   // pre(leftTree);
   // cout<<nl;
   // pre(rightTree);
    if(check(leftTree , rightTree)){
        cout<<"yes"<<nl;
    }
    else{
        cout<<"no"<<nl;
    }
}

int main(){
    t = 1;
    while(t--){
        func();
    }
}