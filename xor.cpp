#pragma GCC optimize("Ofast")
#pragma GCC optimization ("unroll-loops")
 
#include <bits/stdc++.h>
 
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ff first
#define ss second
#define ins insert
#define sz(x) (int)x.size()
#define dbg(x) cout << x << "\n";
 
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
 
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
 
using namespace std;

#define int long long int
 
void TestCase (){
        int n, ans = 0;
        cin >> n;

        vector <int> c(n + 1);
        for(int i = 1; i<=n; i++) cin >> c[i];

        for(int i = 1; i<=n; i += 2){
                int sum = 0, used = 0;
                for(int j = i + 1; j<=n; j += 2){
                        if(sum + used - c[j] > 0){
                                sum -= c[j];
                        }
                        else{
                                int z = sum + used;
                                
                                if(z) ans += min(c[i] - used, c[j] - z) + 1;
                                else ans += min(c[i] - used, c[j]);

                                if(sum + used - c[j] + (c[i] - used) < 0) break;
                                else{
                                        sum -= c[j];
                                        used += abs(sum + used);
                                }
                        }
                        if(j + 1 <= n) sum += c[j + 1];
                        // cout << ans << " " << sum << " " << used << "\n";
                }
                // cout << "\n\n";
        }

        cout << ans;
}

#undef int
 
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
        IOS;
        int T = 1;
        // cin >> T;
        while(T--){
                TestCase();
                cout << "\n";
        }
        return 0;
}