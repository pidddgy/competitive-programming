// https://codeforces.com/problemset/problem/358/D

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

const int maxn = 30050;

int a[maxn], b[maxn], c[maxn];
int dp[maxn][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for(int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0] + b[i], dp[i-1][1] + a[i]);
        dp[i][1] = max(dp[i-1][0] + c[i], dp[i-1][1] + b[i]);
    }

    cout << dp[n][0] << endl;
}

/*

observation - we dont have to skip feeding more than 1 at any time

dp[0] = feed now, dp[1] = feed later

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
