#include<iostream>
#include <bits/stdc++.h>
using namespace std;
//https://oeis.org/search?q=12+%2C+24+%2C+40&sort=&language=&go=Search
#define ll long long
#define mod 1000000007
#define INF 100000007
#define MAX 1000000
#define nl "\n"
typedef vector<ll> vi;
typedef priority_queue<float , vector<float> , greater<float>()> pqmx;
typedef priority_queue<float> pqmn;
typedef pair<int , int> pi;
ll n , t , m , temp , temp2, root , r , p ,q , k;

ll find_sum(int i ,vector<ll> & Bit){
    ll sum = 0;
    while(i > 0){
        sum += Bit[i];
        i -= (i & -i);
    }
    return sum;
}

void update(int i , ll val , vector<ll> & Bit){
    while(i <= 100001){
        Bit[i] += val;
        i += (i & -i);
    }
}

ll prefix_sum(vi & a , vi & b , ll idx){
    return find_sum(idx , a)*idx + find_sum(idx , b);
}

void func(){
    vi Bit1(100002 , 0);
    vi Bit2(100002 , 0);
    cin>>n>>k;
    for(int i = 0;i < k;i++){
        cin>>temp;
        if(temp == 0){
            scanf("%lld %lld %lld",&p,&q,&r);
            update(p , r , Bit1);
            update(q + 1, -r , Bit1);
            update(p , -(long long)r * (p - 1) , Bit2);
            update(q + 1, (long long)r *(q), Bit2);
        }
        else{
            scanf("%lld %lld",&p,&q);
            ll res = prefix_sum(Bit1 , Bit2 , q);
            res -= prefix_sum(Bit1 ,Bit2 , p - 1);
            printf("%lld\n" , res);
        }
    }
}



int main(){
    cin>>t;
    while(t--){ 
        func();
    }
} 