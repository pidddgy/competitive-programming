// https://codeforces.com/contest/1288/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define cerr if(false) cerr

const int maxn = 1500;
const int maxm = 15;
const int MOD = (1e9) + 7;

// at ith index how many cases where it is j
int dp[maxn][maxn];
int dp2[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1) {
                dp[i][j] = 1;
            } else {
                int _ = 0;
                for(int k = j; k >= 1; k--) {
                    _ += dp[i-1][k];
                }

                dp[i][j] = _;
            }
            watch(dp[i][j])
            dp[i][j] %= MOD;
        }
    }

    // for(int i = 1; i <= m; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == 1) {
                int _ = 0;
                for(int k = j; k >= 1; k--) {
                    _ += dp[m][k];
                }

                dp2[i][j] = _;
            } else {
                int _ = 0;
                for(int k = j; k >= 1; k--) {
                    _ += dp2[i-1][k];
                }

                dp2[i][j] = _;
            }
            dp2[i][j] %= MOD;
        }
    }

    // for(int i = 1; i <= m; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cerr << dp2[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp2[m][i];
        ans %= MOD;
    }

    cout << ans << endl;
}