// https://codeforces.com/problemset/problem/118/D

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

const int maxn = 105;
const int MOD = (int)1e8;

int n1, n2, k1, k2;
int dp[maxn][maxn][3][15];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n1 >> n2 >> k1 >> k2;    

    dp[0][0][1][0] = dp[0][0][2][0] = 1;
    for(int i = 0; i <= n1; i++) {
        for(int j = 0; j <= n2; j++) {
            cerr << "currently on " << i << " " << j << endl;
            // add to if we use 1
            for(int k = 1; k <= k1; k++) {
                if(i < k) continue;

                for(int l = 0; l <= k2; l++) {
                    dp[i][j][1][k] += dp[i-k][j][2][l];
                    dp[i][j][1][k] %= MOD;
                }
            }

            // add to dp[2]
            for(int k = 1; k <= k2; k++) {
                if(j < k) continue;

                for(int l = 0; l <= k1; l++) {
                    dp[i][j][2][k] += dp[i][j-k][1][l];
                    dp[i][j][2][k] %= MOD;
                }
            }
        }
    }

    watch(dp[1][0][1][1])
    watch(dp[0][1][2][1])


    int ans = 0;

    for(int i = 1; i <= k1; i++) {
        ans += dp[n1][n2][1][i];
        ans %= MOD;
    }

    for(int i = 1; i <= k2; i++) {
        ans += dp[n1][n2][2][i];
        ans %= MOD;
    }

    cout << ans << endl;
}

/*

dp[num 1][num 2][currently on 1 or 2][how many used]

for use in 1...k1
    for prevused in 1...k2
        transition from dp[i-use][j][1][prevused]
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
