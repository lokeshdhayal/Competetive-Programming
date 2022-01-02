 
/*
       ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄
      ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
      ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌
      ▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌ ▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌▐░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌ ▀▀▀▀▀▀█░▌▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌
      ▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌
      ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░▌
       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀  
 
 #can_change_the_world_with_the_help_of_0_1
                                    -darshan786    */
 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,k,n) for(int i = (k); i < (int)(n); ++i)
#define FOREQ(i,k,n) for(int i = (k); i <= (int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" ,stdin);
    freopen("output.txt" , "w" , stdout);
#endif
    
  ll n, x, y, c;
  while(cin >> n >> x >> y >> c) {
    ll r[4] = {y - 1, x - 1, n - y, n - x};

    ll t = 0;
    ll cnt = 1;
    for(;;) {
      REP(i, 4) {
        cnt += t - min(max(0LL, t - r[i]) + max(0LL, t - 1 - r[(i+1) % 4]), t);
      }
      if(cnt >= c) break;
      ++t;
    }
    cout << t << endl;
  }

#ifndef ONLINE_JUDGE
    cout << "Running Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s .\n";
#endif
}
