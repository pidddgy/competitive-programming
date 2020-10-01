// https://codeforces.com/problemset/problem/580/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

const int maxn = 25;

int n, m, k;
int a[maxn];
int c[maxn][maxn];

int dp[(1<<18)+500][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < (1<<18)+500; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = LLONG_MIN;
        }
    }

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        cin >> c[x-1][y-1];
    }

    for(int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }

    // "push up" dp
    for(int mask = 0; mask <= (1 << n)-1; mask++) {
        for(int i = 0; i < n; i++) {
            if((mask & (1 << i)) == 0) continue;
            for(int j = 0; j < n; j++) {
                if(mask & (1 << j)) continue;   
                dp[mask | (1 << j)][j] = max(dp[mask | (1 << j)][j], dp[mask][i] + a[j] + c[i][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= (1 << n)-1; i++) {
        if(__builtin_popcount(i) == m) {
            for(int j = 0; j < n; j++) {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans << endl;
}

/*

dp[item #][mask][last used(current)] = max satisfaction
time complexity ->  2**18 * 18**3

kick out dimension = dp[mask][last used(current)]
    -> use builtin popcount
    -> time complexity: 2**18 * 18**2 = 84 934 656
        -> iterate over mask, last used, next

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
