// https://codeforces.com/contest/1389/problem/B

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
#define all(x) (x).begin(), (x).end()

const int maxn = 100500;

int a[maxn];
int dp[maxn][10];

void solve() {
    int n, k, z;
    cin >> n >> k >> z;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    dp[1][0] = a[1];

    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + a[i];
        for(int it = 0; it < 10; it++) {
            for(int j = 1; j <= z; j++) {
                dp[i-1][j] = max(dp[i-1][j], dp[i][j-1] + a[i-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= z; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= z; j++) {
            if(i + 2*j - 1 == k) {
                if(dp[i][j] > ans) {
                    cerr << i << " " << j << " " << dp[i][j] << endl;
                }
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << endl;

    // Clear
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= z; j++) {
            dp[i][j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
