// https://codeforces.com/contest/1398/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 203;
int dp[maxn][maxn][maxn];
int r[maxn], g[maxn], b[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int R, G, B;
    cin >> R >> G >> B;

    for(int i = 1; i <= R; i++) {
        cin >> r[i];
    }

    for(int i = 1; i <= G; i++) {
        cin >> g[i];
    }
    
    for(int i = 1; i <= B; i++) {
        cin >> b[i];
    }

    sort(r+1, r+R+1, greater<int>());
    sort(g+1, g+G+1, greater<int>());
    sort(b+1, b+B+1, greater<int>());

    int ans = 0;
    for(int i = 0; i <= R; i++) {
        for(int j = 0; j <= G; j++) {
            for(int k = 0; k <= B; k++) {
                // cerr << "on " << i << " " << j << " " << k << endl;
                for(char l = 0; l <= 1; l++) {
                    for(char m = 0; m <= 1; m++) {
                        for(char n = 0; n <= 1; n++) {
                            if(l+m+n != 2) continue;

                            // vector<int> v;
                            int x = -1, y = -1;

                            if(l) {
                                // v.emplace_back(r[i]);
                                if(x == -1) x = r[i];
                                else if(y == -1) y = r[i];

                                if(!i) continue;
                            }

                            if(m) {
                                // v.emplace_back(g[j]);
                                if(x == -1) x = g[j];
                                else if(y == -1) y = g[j];
                                if(!j) continue;
                            }

                            if(n) {
                                // v.emplace_back(b[k]);
                                if(x == -1) x = b[k];
                                else if(y == -1) y = b[k];
                                if(!k) continue;
                            }

                            // cerr << "can use " << l << " " << m << " " << n << endl;

                            dp[i][j][k] = max(dp[i][j][k], dp[i-l][j-m][k-n]+(x*y));
                        }
                    }
                }
                // cerr << dp[i][j][k] << endl;
                ans = max(ans, dp[i][j][k]);
            }
        }
    }

    // cout << dp[R][G][B] << endl;
    cout << ans << endl;
}

/*

dp[R][G][B]

for i in 1 to R
    for j in 1 to G
        for k in 1 to B
            for l in 0 to 1 inclusive
                for m in 0 to 1 inclusive
                    for n in 0 to 1 inclusive
                        if number of non zero elements is not 2 then continue

                        transition from dp[i-l][j-m][k-n], add area

64 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
