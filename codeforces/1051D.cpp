// https://codeforces.com/contest/1051/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int MOD = 998244353, maxn = 1005, maxk = 2005;

// column, number of components, mask
int dp[maxn][maxk][5];
int n, k;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    /*
    0 -> WW
    1 -> WB
    2 -> BW
    3 -> BB
    */

    dp[1][1][0] = 1;
    dp[1][2][1] = 1;
    dp[1][2][2] = 1;
    dp[1][1][3] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3]) % MOD; // WW
            dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j-2][2] + dp[i-1][j-1][3]) % MOD; // WB
            dp[i][j][2] = (dp[i-1][j-1][0] + dp[i-1][j-2][1] + dp[i-1][j][2] + dp[i-1][j-1][3]) % MOD; // BW
            dp[i][j][3] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3]) % MOD; // WW
        }
    }

    int ans = 0;
    for(int i = 0; i <= 3; i++) {
        ans += dp[n][k][i];
        ans %= MOD;
    }

    cout << ans << endl;
}
