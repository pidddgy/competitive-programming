// https://codeforces.com/problemset/problem/607/B

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

const int maxn = 505;

int c[maxn];

int dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int len = 1; len <= n; len++) {
        for(int l = 1, r = len; r <= n; l++, r++) {
            if(len == 1) {
                dp[l][r] = 1;
            } else {
                dp[l][r] = dp[l+1][r]+1;
                if(c[l] == c[l+1]) {
                    dp[l][r] = min(dp[l][r], dp[l+2][r]+1);
                }

                for(int i = l+2; i <= r; i++) {
                    if(c[l] == c[i]) {
                        dp[l][r] = min(dp[l][r], dp[l+1][i-1]+dp[i+1][r]);
                    }
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }

    cout << dp[1][n] << endl;
}

/*

observations
    - answer always <= n


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
