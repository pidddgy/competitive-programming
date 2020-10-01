// https://codeforces.com/contest/1096/problem/D

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

const int maxn = 100500;

int a[maxn];
int dp[maxn][6];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // for(int i = 0; i < maxn; i++) {
    //     for(int j = 0; j < 6; j++) {
    //         dp[i][j] = INT_MAX;
    //     }
    // }

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // dp[i][j] = first i elements of s, made 1...j of "hard" not be subsequence
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 4; j++) {
            dp[i][j] = dp[i-1][j];
        }

        // either get rid of previous letters, or change current letter
        if(s[i] == 'h') dp[i][1] += a[i];
        if(s[i] == 'a') dp[i][2] = min(dp[i-1][1], dp[i][2]+a[i]);
        if(s[i] == 'r') dp[i][3] = min(dp[i-1][2], dp[i][3]+a[i]);
        if(s[i] == 'd') dp[i][4] = min(dp[i-1][3], dp[i][4]+a[i]);
    }


    int ans = LLONG_MAX;
    for(int i = 1; i <= 4; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << endl;
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
