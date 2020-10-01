// https://codeforces.com/problemset/problem/163/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

const int MAXN = 5005;
const int MOD = (int)1e9+7;

int dp[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int n = sz(s);
    int m = sz(t);
    s = "."+s;
    t = "."+t;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j-1];
            dp[i][j] %= MOD;
            if(s[i] == t[j]) {
                dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;

                dp[i][j]++;
                dp[i][j] %= MOD;
            }
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[i][m];
        ans %= MOD;
    }

    cout << ans << endl;
}

/*

dp[i][j] = substring ending at i, subsequence ending at j
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
