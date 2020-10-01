// https://codeforces.com/problemset/problem/106/C

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

const int maxn = 1005;
const int maxm = 15;

int dp[maxm][maxn][105];
int a[maxn], b[maxn], c[maxn], d[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;

    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= 0; j--) {
            for(int k = 0; k <= a[i]/b[i]; k++) {
                // buy a stuffed bun
                if(j >= c[i]) {
                    dp[i][j-c[i]][k+1] = max(dp[i][j-c[i]][k+1], dp[i][j][k] + d[i]);
                }

                // buy non stuffed bun
                if(j >= c0) {
                    dp[i][j-c0][k] = max(dp[i][j-c0][k], dp[i][j][k] + d0);
                }

                // dont buy 
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][k]);
            }
        }
    }

    watch(dp[1][8][1])
    watch(dp[1][6][2])
    // watch(dp[2][6][2])
    watch(dp[2][5][1])

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= a[m]/b[m]; j++) {
            ans = max(ans, dp[m][i][j]);
        }
    }

    cout << ans << endl;
}

/*

put a bound on max number of buns of each type we can buy

dp[i][j][k] = on the ith bun if we have j dough and bought k of the current bun

iterate from max dough to 0 dough

when buying the current stuffed bun
push from dp[i][j] to dp[i][j-c[i]][k+1]

when buying non stuff bun
push from dp[i][j] to dp[i][j-c0][k]

when not doing anything
push from dp[i][j] to dp[i+1][j][0]


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
