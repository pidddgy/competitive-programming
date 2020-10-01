// https://codeforces.com/problemset/problem/543/A

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

const int maxn = 550;

int a[maxn];
int dp[2][maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, b, mod;
    cin >> n >> m >> b >> mod;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0][0][0] = 1;

    for(int i = 1; i <= n; i++) {
        int j = i%2;
        int prev = j^1;

        for(int k = 0; k <= m; k++) {
            for(int l = 0; l <= b; l++) {
                dp[j][k][l] = dp[prev][k][l];

                if(k > 0 and l >= a[i]) {
                    dp[j][k][l] += dp[j][k-1][l-a[i]];
                    dp[j][k][l] %= mod;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 0; i <= b; i++) {
        ans += dp[n%2][m][i];
        ans %= mod;
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
