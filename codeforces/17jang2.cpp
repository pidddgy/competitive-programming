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
const int maxm = 25;

int n, m;
int a[maxn];

// index, changes used, cur
int dp[maxn][maxm][4];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        char x;
        cin >> x;

        if(x == 'H') a[i] = 1;
        if(x == 'P') a[i] = 2;
        if(x == 'S') a[i] = 3;
    }

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxm; j++) {
            for(int k = 0; k < 4; k++) {
                dp[i][j][k] = -(1e18);
            }
        }
    }

    dp[0][0][1] = dp[0][0][2] = dp[0][0][3] = 0;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 1; k <= 3; k++) {
                // k = current, l = last
                for(int l = 1; l <= 3; l++) {
                    if(k != l and !j) continue;

                    if(k == l) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][l]+(k==a[i]));
                    } else {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][l]+(k==a[i]));
                    }

                    ans = max(ans, dp[i][j][k]);
                }
            }
        }
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
