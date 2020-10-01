// https://codeforces.com/contest/1350/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int dp[100500];
int a[100500];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++) {
            dp[i] = max(dp[i], 1);
            for(int j = i+i; j <= n; j += i) {
                if(a[j] > a[i]) {
                    dp[j] = max(dp[j], dp[i]+1);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, dp[i]);
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            dp[i] = 0;
        }
    }
}
