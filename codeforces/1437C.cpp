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

const int maxn = 250;

int n;
int a[maxn];
int dp[maxn][600];

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 600; j++) {
            dp[i][j] = 1e18;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 500; j++) {
            if(i == 1) dp[i][j] = abs(a[i]-j);
            else for(int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(a[i]-j));
            }
        }
    }

    int ans = 1e18;
    for(int i = 1; i <= 500; i++) {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--) solve();
}

/*

guess: do not put any at above 500
try increasing bound if doesn't work

guess: sort the dishes, times we put them in are increasing
dp[i][j] = dish i, last = j, min cost

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
