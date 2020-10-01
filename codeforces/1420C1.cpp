// https://codeforces.com/contest/1420/problem/C1

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

const int maxn = 300500;

int a[maxn];
int dp[maxn][2];
void solve() {
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> a[i];

    dp[0][1] = -1e17;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]-a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]+a[i]);
    }

    cout << dp[n][1] << endl;

    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*


dp[i][j] = [odd/even][at i]
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
