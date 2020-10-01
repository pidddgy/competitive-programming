// https://codeforces.com/contest/1194/problem/D

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

const int maxn = 100500;

int dp[maxn];
void solve() {
    int n, k;
    cin >> n >> k;

    dp[0] = false;
    for(int i = 1; i <= n; i++) {
        bool win = false;

        if(i >= 1) win |= (!dp[i-1]);
        if(i >= 2) win |= (!dp[i-2]);
        if(i >= k) win |= (!dp[i-k]);

        dp[i] = win;
    }

    if(dp[n]) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
    for(int i = 0; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
