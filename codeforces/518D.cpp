// https://codeforces.com/problemset/problem/518/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

ld dp[3000][3000];
map<int, int> mp;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    ld p;
    int n, t;
    cin >> n >> p >> t;

    dp[0][0] = 1;

    ld fail = 1.0-p;

    for(int i = 0; i <= t; i++) {
        for(int j = 0; j <= n; j++) {
            if(j == n) {
                dp[i+1][j] += dp[i][j];
            } else {
                dp[i+1][j] += dp[i][j] * fail;
                dp[i+1][j+1] += dp[i][j] * p;
            }
            // cerr << dp[i][j] << " ";
        }
        // cerr << endl;
    }

    ld ans = 0;

    for(ld i = 0; i <= n; i++) {
        ans += i*dp[t][(int)i];
    }

    cout << ans << endl;
}

/*

dp[1][2] = dp[0][0]*p + dp[0][1]
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
