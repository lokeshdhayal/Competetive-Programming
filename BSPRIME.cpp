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

ll b[150000001];

string binary(ll i){
	string res = "";
	while(i > 0){
		res += (i & 1) ? '1' : '0';
		i >>= 1;
	}
	reverse(res.begin() , res.end());
	return res;
}

void sieve(){
	vector<bool> a(7250000 , false);
	for(int i = 2;i < 7250000;i++){
		if(a[i] == false){
			for(int j = i * i;j < 7250000;j += i){
				a[i] = true;
			}
		}
	}
	string res = "";
	k = 1;
	bool flag = false;
	for(int i = 2;i < 7250000 && k < 15;i++){
		if(a[i] == false){
		//	cout<<i<<" ";
			string s = binary(i);
			//cout<<s<<"\n";
		//	res += s;
			for(char j : s){
				if(k > 15000000){
					flag = true;
					break;
				}
				if(j == '1'){
					b[k] = b[k - 1] + 1;
				}
				else{
					b[k] = b[k - 1];
				}
			//	b[k] = b[k - 1] + (j == '1') ? 1 : 0;
			//	cout<<b[k]<<" "<<b[k - 1]<<" "<<j<<'\n';
				k++;
			}
		}
		if(flag){
			break;
		}
	}
	//cout<<res<<'\n';
}

void func(){
	cin>>n;
	cout<<b[n]<<'\n';
}



int main(){
	time_t start, end;
	time(&start); 
	sieve();
	cout<<"yes";
	cin>>t;
	while(t--){
		func();
	}
	time(&end);
	double time_taken = double(end - start); 
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    return 0;
} 