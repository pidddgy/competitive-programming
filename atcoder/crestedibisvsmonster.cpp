// https://atcoder.jp/contests/abc153/tasks/abc153_e

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define int long long

int dp[10000060];

signed main() {
    int H, N;
    cin >> H >> N;

    for(int i = 1; i <= 10000050; i++) {
        dp[i] = INT_MAX;
    }
    
    dp[0] = 0;
    int ans = INT_MAX;
    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        // watch(a)
        // watch(b)

        for(int j = 0; j <= H; j++) {
            dp[j+a] = min(dp[j+a], dp[j]+b);
            // cout << "setting dp_" << j+a << " to " << dp[j+a] << endl;

            if(j+a >= H) {
                ans = min(ans, dp[j+a]);
            }

            // watch(dp[j])
            // cout << "we can get to " << j+a << " with " << dp[j]+b << endl;
        }
        // cout << endl;
    }

    cout << ans << endl;
    
}