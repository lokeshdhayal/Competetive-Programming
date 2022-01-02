https://github.com/indy256/codelibrary/blob/master/cpp/numbertheory/rational.h



---------- Floyd’s Cycle-Finding Algorithm----------
ll floydCycleFinding(int x0) {
    int tortoise = f(x0), hare = f(f(x0));
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
    int mu = 0; hare = x0;
    while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
    int lambda = 1; hare = f(tortoise);
    while (tortoise != hare) { hare = f(hare); lambda++; }
    return lambda;
}



-----------Baby Step Gaint Step --------


int solve(int a, int b, int m) {
    a %= m, b %= m;
    int k = 1, add = 0, g;
    while ((g = gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }

    int n = sqrt(m) + 1;
    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<int, int> vals;
    for (int q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (int p = 1, cur = k; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            int ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

------------Bitwise Sieve---------

bool ifnotPrime(int prime[], int x) {
   return (prime[x/64]&(1<<((x>>1)&31)));
}
bool makeComposite(int prime[], int x) {
   return prime[x/64]|=(1<<((x>>1)&31));
}
void bitWiseSieve(int n){
   int prime[n/64];
   memset(prime, 0, sizeof(prime));
   for (int i = 3; i<= sqrt(n); i= i+2) {
      if (!ifnotPrime(prime, i))
      for (int j=pow(i,2), k= i<<1; j<n; j+=k)
      makeComposite(prime, j);
   }
   for (int i = 3; i <= n; i += 2)
   if (!ifnotPrime(prime, i))
      printf("%d\t", i);
}

-----------Pollard rho factorization------


#define abs_val(a) (((a)>0)?(a):-(a))
ll mulmod(ll a, ll b, ll c) {
    ll x = 0, y = a % c;
    while (b > 0) {
        if (b % 2 == 1) x = (x + y) % c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}
ll pollard_rho(ll n) {
    int i = 0, k = 2;
    ll x = 3, y = 3;
    while (1) {
        i++;
        x = (mulmod(x, x, n) + n - 1) % n;
        ll d = gcd(abs_val(y - x), n);
        if (d != 1 && d != n) return d;
        if (i == k) y = x, k *= 2;
    }
}



--------------ModInt---------------


template<int MOD>
struct ModInt {
    long long v;
    ModInt(long long _v = 0) {v = (-MOD < _v && _v < MOD) ? _v : _v % MOD; if (v < 0) v += MOD;}
    ModInt& operator += (const ModInt &other) {v += other.v; if (v >= MOD) v -= MOD; return *this;}
    ModInt& operator -= (const ModInt &other) {v -= other.v; if (v < 0) v += MOD; return *this;}
    ModInt& operator *= (const ModInt &other) {v = v * other.v % MOD; return *this;}
    ModInt& operator /= (const ModInt &other) {return *this *= inverse(other);}
    bool operator == (const ModInt &other) const {return v == other.v;}
    bool operator != (const ModInt &other) const {return v != other.v;}
    friend ModInt operator + (ModInt a, const ModInt &b) {return a += b;}
    friend ModInt operator - (ModInt a, const ModInt &b) {return a -= b;}
    friend ModInt operator * (ModInt a, const ModInt &b) {return a *= b;}
    friend ModInt operator / (ModInt a, const ModInt &b) {return a /= b;}
    friend ModInt operator - (const ModInt &a) {return 0 - a;}
    friend ModInt power(ModInt a, long long b) {ModInt ret(1); while (b > 0) {if (b & 1) ret *= a; a *= a; b >>= 1;} return ret;}
    friend ModInt inverse(ModInt a) {return power(a, MOD - 2);}
    friend ostream& operator << (ostream &os, const ModInt &m) {return os << m.v;}
};
typedef ModInt<998244353> M;


------------BIG INTEGER ------------


string Addition(string a,string b);
string Multiplication(string a,string b);
string Multiplication(string a,int k);
string Subtraction(string a,string b);
string Division(string a,string b);
string Division(string a,int k);
string Div_mod(string a,string b);
int Div_mod(string a,int k);
string cut_leading_zero(string a);
int compare(string a,string b);



#define MAXL 1010
#define MAXS 1000010
#define MAXP 90000
#define INFIN 1001001001

#define pq priority_queue
#define btc(x) __builtin_popcount(x)
#define mp(x, y) make_pair(x, y)
#define paii pair< int, int >
#define pasi pair< string, int >
#define pais pair< int, string >
#define mem(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define pi (2*acos(0))
#define oo 1<<20
#define dd double
#define ll long long int
#define llu long long unsigned
#define ERR 1e-5
#define fst first
#define sec second
#define SZ(a) (int)a.size()
#define All(a) a.begin(),a.end()

#define SIZE 1000
#define REP(i,n) for(i=0; i<n; i++)
#define REV(i,n) for(i=n; i>=0; i--)
#define FOR(i,p,k) for(i=p; i<k; i++)
#define Sort(x) sort(x.begin() , x.end())
#define Reverse(x) reverse(x.begin() , x.end())


string Multiplication(string a,string b)
{
    int i, j, multi, carry;
    string ans, temp;

    ans = "0";
    REV(j,SZ(b)-1)
    {
        temp = "";
        carry = 0;
        REV(i,SZ(a)-1)
        {
            multi = (a[i]-'0')*(b[j]-'0')+carry;
            temp += (multi%10+'0');
            carry = multi/10;
        }
        if( carry ) temp += (carry+'0');
        Reverse(temp);
        temp += string(SZ(b)-j-1,'0');
        ans = Addition(ans,temp);
    }
    ans = cut_leading_zero(ans);
    return ans;
}

string Multiplication(string a,int k)
{
    string ans;
    int i, sum, carry=0;

    REV(i,SZ(a)-1)
    {
        sum = (a[i]-'0')*k+carry;
        carry = sum/10;
        ans+=(sum%10)+'0';
    }
    while(carry)
    {
        ans += (carry%10)+'0';
        carry/=10;
    }
    Reverse(ans);
    ans = cut_leading_zero(ans);
    return ans;
}

string Addition(string a,string b)
{
    int carry=0, i;
    string ans;

    if( SZ(a)>SZ(b) ) b = string(SZ(a)-SZ(b),'0')+b;
    if( SZ(b)>SZ(a) ) a = string(SZ(b)-SZ(a),'0')+a;

    ans.resize(SZ(a));

    REV(i,SZ(a)-1)
    {
        int sum = carry+a[i]+b[i]-96;
        ans[i] = (char)(sum%10+'0');
        carry = sum/10;
    }
    if( carry ) ans.insert(0,string(1,carry+'0'));
    ans = cut_leading_zero(ans);
    return ans;
}

string Subtraction(string a,string b)
{
    int borrow = 0, i, sub;
    string ans;
    if( SZ(b)<SZ(a) ) b = string(SZ(a)-SZ(b),'0')+b;
    REV(i,SZ(a)-1)
    {
        sub = a[i]-b[i]-borrow;
        if( sub<0 )
        {
            sub += 10;
            borrow = 1;
        }
        else borrow = 0;
        ans += sub+'0';
    }
    Reverse( ans );
    ans = cut_leading_zero(ans);
    return ans;
}

string Division(string a,string b)
{
    string mod, temp, ans="0";
    int i, j;

    REP(i,SZ(a))
    {
        mod += a[i];
        mod = cut_leading_zero(mod);
        FOR(j,0,10)
        {
            temp = Multiplication(b,j);
            if( compare(temp,mod)==1 )
                break;
        }
        temp = Multiplication(b,j-1);
        mod = Subtraction(mod,temp);
        ans += (j-1)+'0';
    }
    mod = cut_leading_zero(mod);
    ans = cut_leading_zero(ans);
    return ans;
}

string Division(string a,int k)
{
    int i, sum=0;
    string ans = "0";

    REP(i,SZ(a))
    {
        sum = (sum*10+(a[i]-'0'));
        ans += (sum/k)+'0';
        sum = sum%k;
    }
    ans = cut_leading_zero(ans);
    return ans;
}

string Div_mod(string a,string b)
{
    string mod, temp, ans="0";
    int i, j;

    REP(i,SZ(a))
    {
        mod += a[i];
        mod = cut_leading_zero(mod);

        FOR(j,1,10)
        {
            temp = Multiplication(b,j);
            if( compare(temp,mod)>0 )
                break;
        }
        temp = Multiplication(b,j-1);
        mod = Subtraction(mod,temp);
        ans += (j-1)+'0';
    }
    mod = cut_leading_zero(mod);
    ans = cut_leading_zero(ans);
    return mod;
}

int Div_mod(string a,int k)
{
    int i, sum=0;
    REP(i,SZ(a))
        sum = (sum*10+(a[i]-'0'))%k;
    return sum;
}

int compare(string a,string b)
{
    int i;
    a = cut_leading_zero(a);
    b = cut_leading_zero(b);

    if( SZ(a)>SZ(b) ) return 1;
    if( SZ(a)<SZ(b) ) return -1;
    REP(i,SZ(a))
    {
        if( a[i]>b[i] ) return 1;
        else if( a[i]<b[i] ) return -1;
    }
    return 0;
}

string cut_leading_zero(string a)
{
    string s;
    int i;
    if( a[0]!='0' ) return a;
    REP(i,SZ(a)-1) if( a[i]!='0' ) break;
    FOR(i,i,SZ(a)) s+=a[i];
    return s;
}