// https://codeforces.com/problemset/problem/1221/D

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

const int maxn = 300500;
int n;
int a[maxn], b[maxn];
int dp[maxn][5];

void solve() {
    cin >> n;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 2; j++) {
            dp[i][j] = LLONG_MAX;
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    for(int i = 0; i <= 2; i++) {
        dp[1][i] = b[1]*i;
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 2; k++) {
                // j = current, k = prev

                if(a[i]+j != a[i-1]+k) {
                    dp[i][j] = min(dp[i][j], dp[i-1][k] + b[i]*j);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 2; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    int ans = LLONG_MAX;
    for(int i = 0; i <= 2; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << endl;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 2; j++) {
            dp[i][j] = LLONG_MAX;
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

dp[n][3]

min cost to fix first i boards, ith board is raised j amount of times

1 = 0


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
