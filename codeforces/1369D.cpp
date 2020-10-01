// https://codeforces.com/contest/1369/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
const int maxn = 2000500;
const int MOD = 1000000007;

int dp[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    dp[3] = 4;

    for(int i = 4; i <= 2e6; i++) {
        if(i%3==0) {
            dp[i] = (2LL*dp[i-2]) + dp[i-1] + 4;
        } else {
            dp[i] = (2LL*dp[i-2]) + dp[i-1];
        }

        dp[i] %= MOD;
        // cout << "dp_"<<i << " is " << dp[i] << endl;
    }

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }
}
