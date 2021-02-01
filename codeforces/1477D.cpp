// https://codeforces.com/contest/1447/problem/D

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

const int maxn = 5500;

int dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    string a, b;
    cin >> a >> b;

    a = "."+a;
    b = "."+b;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max({0LL, dp[i-1][j]-1, dp[i][j-1]-1});
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+2);
            }
            ans = max(ans, dp[i][j]);
            // cerr << dp[i][j] << " ";
        }
        // cerr << endl;
    }

    // cout << dp[n][m] << endl;

    cout << ans << endl;
} 

/*

both endpoints are starts and ends of lcs

amortized idk

something not in use: only 26 letters

it is only worth adding 4 characters to increase lcs by 1

only consid


dp[i][j] = answer ending at i, j
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
