#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
//https://www.hackerearth.com/practice/codemonk/
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

bool check1(string s , int h , int min){
    int val = ( min*((s[0]  - '0') * 10 + (s[1] - '0')) + ((s[3]  - '0') * 10 + (s[4] - '0')) );
    if(((s[3]  - '0') * 10 + (s[4] - '0')) >= min){
        return false;
    }
    if(((s[0]  - '0') * 10 + (s[1] - '0')) >= h){
        return false;
    }
    return val < min * h;
}


bool check(string s , int min , int h){
    if(s[0] == '0' || s[0] == '1' || s[0] == '8'){
        s[0] = s[0];
    }
    else if(s[0] == '2'){
        s[0] = '5';
    }
    else if(s[0] == '5'){
        s[0] = '2';
    }
    else{
        return false;
    }
    if(s[1] == '0' || s[1] == '1' || s[1] == '8'){
        s[1] = s[1];
    }
    else if(s[1] == '2'){
        s[1] = '5';
    }
    else if(s[1] == '5'){
        s[1] = '2';
    }
    else{
        return false;
    }
    if(s[4] == '0' || s[4] == '1' || s[4] == '8'){
        s[4] = s[4];
    }
    else if(s[4] == '2'){
        s[4] = '5';
    }
    else if(s[4] == '5'){
        s[4] = '2';
    }
    else{
        return false;
    }
    if(s[3] == '0' || s[3] == '1' || s[3] == '8'){
        s[3] = s[3];
    }
    else if(s[3] == '2'){
        s[3] = '5';
    }
    else if(s[3] == '5'){
        s[3] = '2';
    }
    else{
        return false;
    }
    char p = s[0];
    s[0] = s[4];
    s[4] = p;
    p = s[1];
    s[1] = s[3];
    s[3] = p;
  // cout<<s<<" ";
    return check1(s , min , h);
}


string change(int val,int h , int min){
    val = val % (h * min);
    string s = "lokes";
    s[2] = ':';
    int p = val / min;
    s[1] = (p % 10  + '0');
    p /= 10;
    s[0] = (p % 10  + '0');
    p = val % min;
    s[4] = (p % 10  + '0');
    p /= 10;
    s[3] = (p % 10  + '0');
    return s;
}

void func(){
    cin>>n>>k;
    string s;
    cin>>s;
    if(s.size()%k != 0){
        cout<<-1<<'\n';
        return;
    }
    bool flag = true;
    vector<int> a(26 , 0);
    for(char i : s){
        a[i - 'a']++;
    }
    for(int i = 0;i < 26;i++){
        if(a[i]%k != 0){
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<s<<'\n';
        return;
    }
    for(int i = 0;i < s.size();i++){
        if(s[i] != 'a'){
            p = i;
            break;
        }
    }
    char l = (s[p] + 1);
    string res = "";
    for(char i = 0;i < k - 1;i++){
        res += l;
    }
    for(int i = k-1;i < s.size();i++){
        res += 'a';
    }
    reverse(res.begin() , res.end());
    if(p >= n - 1 - k){
        res[n - 1 - k] = l;
    }
    else{
        res[p] = l;
    }
    cout<<res<<'\n';
}



int main(){
    cin>>t;
    while(t--){ 
        func();
    }
} 