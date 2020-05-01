// https://codeforces.com/contest/1324/problem/E

#include <bits/stdc++.h>
#define int long
#define maxn 6000
using namespace std;

int dp[maxn][maxn];

bool in(int x, int l, int r) {
    if(l <= x and x <= r) return true;
    return false;
}

signed main() {
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++) dp[i][j] = INT_MIN;

    int n, h, l, r;
    cin >> n >> h >> l >> r;

    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    dp[0][0] = 0;

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        for(int j = 0; j <= n; j++) {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+in((sum-j)%h, l, r));
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + in((sum-j-1)%h, l, r));
        }
    }

    int ma = 0;
    for(int i = 0; i <= n; i++) {
        ma = max(ma, dp[n][i]);
    }

    cout << ma << endl;
}