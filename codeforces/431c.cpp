// https://codeforces.com/contest/431/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr

int dp[2][20000];
const int MOD = 1000000007;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            cerr << "on " << j << " " << i << endl;
            if(i >= j) {
                if(j>=d) {
                    cerr << "1 adding " << dp[1][i-j] + dp[0][i-j] << " to " << i << " from index " << i-j << endl;
                    dp[1][i] += dp[1][i-j] + dp[0][i-j];
                } else {
                    cerr << "not" << endl;
                    cerr << "adding 1 " << dp[1][i-j] << endl;
                    cerr << "adding 0 " << dp[0][i-j] << endl;
                    dp[1][i] += dp[1][i-j];
                    dp[0][i] += dp[0][i-j];
                }
            }

            dp[1][i] %= MOD;
            dp[0][i] %= MOD;
        }
    }

    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j <= n; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << dp[1][n] << endl;
}