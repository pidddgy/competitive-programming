// Link

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

string s, t;
int k;
const int maxk = 100500;
const int MOD = (int)1e9+7;

// 0 = good
// 1 = bad
int dp[2][maxk];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;
    cin >> k;

    int n = sz(s);

    s = "."+s;
    t = "."+t;

    int good = 0, bad = 0;
    for(int i = 1; i <= n; i++) {
        string str = ".";
        for(int j = i; j <= n; j++) {
            str += s[j];
        }
        for(int j = 1; j <= i-1; j++) {
            str += s[j];
        }

        if(str == t) {
            good++;
        } else {
            bad++;
        }
    }

    if(s == t) {
        dp[0][0] = 1;
    } else {
        dp[1][0] = 1;
    }

    for(int i = 1; i <= k; i++) {
        dp[0][i] = dp[0][i-1] * (good-1) + dp[1][i-1] * good;
        dp[1][i] = dp[1][i-1] * (bad-1) + dp[0][i-1] * bad;

        dp[0][i] %= MOD;
        dp[1][i] %= MOD;
    }

    cout << dp[0][k] << endl;
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
