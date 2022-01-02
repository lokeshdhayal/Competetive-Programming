#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
lli dp[1000001];
lli inv[1000001];

lli power(lli a , lli n)
{
	lli result = 1;
	
	while(n)
	{
		if(n & 1) result = (result * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return result;
}


void init(string & input_string)
{
	lli p = 31;
	lli p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0] - 'a' + 1);
	
	
	for(int i=1;i<input_string.size();i++)
	{
		char ch = input_string[i];
		
		p_power = (p_power * p) % mod;
		inv[i] = power(p_power , mod - 2);
		
		dp[i] = (dp[i-1] + (ch - 'a' + 1)*p_power) % mod;
	}
}

lli substringHash(int L , int R)
{
	int result = dp[R];
	
	if(L > 0) result -= dp[L-1];
	
	result = (result * inv[L]) % mod;
	
	return result;
}




int main()
{
	string input_string;
	int tc , L , R;
	
	cin>>input_string;
	init(input_string);
	
	cin>>tc;
	
	REP(i , tc)
	{
		cin>>L>>R;
		cout<<substringHash(L , R)<<endl;
	}
}




/*

struct hashF{
    vector<ll> dp;
    vector<ll> inv;
    ll n;
    ll mod;
    hashF(string & s,int m){
        n = (int)s.size();
        mod = m;
        dp.assign(n,0);
        inv.assign(n,0);
        dp[0] = s[0] - 'a' + 1;
        ll p = 31;
        ll power = 1;
        inv[0] = binpow(1,mod-2,mod);
        int in = binpow(31,m-2,m);
        ll r = in;
        for(int i = 1;i < n;i++){
            power = power * p % mod;
            inv[i] = r;
            r = r * in % mod;
            dp[i] = (dp[i - 1] + (s[i] - 'a' + 1)*power ) % mod;
        }
    }
    ll substrHash(int L , int R){
        ll result = dp[R];
        if(L > 0) result = (result - dp[L-1] + mod)%mod;
        result = (result * inv[L]) % mod;
        return result;
    }
};


*/



int inv[2000005];
struct hashF{
    vector<int> dp;
    ll n;
    ll mod;
    hashF(string & s,ll m){
        n = (int)s.size();
        mod = m;
        dp.assign(n,0);
        dp[0] = s[0] - 'a' + 1;
        ll p = 31;
        ll power = 1;
        for(int i = 1;i < n;i++){
            power = power * p % mod;
            dp[i] = (dp[i - 1] + (ll)(s[i] - 'a' + 1)*power ) % mod;
        }
    }
    ll substrHash(int L , int R){
        ll result = dp[R];
        if(L > 0) result = (result - dp[L-1] + mod)%mod;
        result = (result * inv[L]) % mod;
        return result;
    }
};

void init(){
    ll p = 31;
    ll power = 1;
    for(int i = 0;i < 2000005;i++){
        inv[i] = binpow(power,mod-2,mod);
        power = p * power % mod;
    }
}

ll getHash(string & key,ll mod){
    ll value = 0;
    ll p = 31;
    ll p_power = 1;
    for(char ch : key){
        value = (value + (ch - 'a' + 1)*p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return value;
}

