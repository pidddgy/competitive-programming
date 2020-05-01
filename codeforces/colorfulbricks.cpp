// https://codeforces.com/contest/1081/problem/C

#include <bits/stdc++.h>
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define maxn 2005
#define MOD 998244353
using namespace std;

int dp[maxn][maxn];

signed main() {

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) {
            if(j == 0 or j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }
        }
    }

    // watch(dp[n-1][k])

    int color = 1;

    for(int i = 1; i <= k; i++) {
        color *= m-1;
        color %= MOD;
    }

    color *= m;
    color %= MOD;

    // watch(color)

    cout << (dp[n-1][k] * color) % MOD << endl;
}