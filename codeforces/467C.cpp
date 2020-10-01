// https://codeforces.com/problemset/problem/467/C

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

const int maxn = 5050;

int n, m, k;
int a[maxn];
int psa[maxn];
int dp[maxn][maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            dp[i][j] = INT_MIN;
    
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
    }

    dp[0][0] = 0;

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        for(int j = m; j <= n; j++) {
            int val = dp[i-1][j-m] + (psa[j]-psa[j-m]);
            
            dp[i][j] = max({dp[i][j], dp[i][j-1], val});
            ans = max(ans, dp[i][j]);
        }
    }

    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= n; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*
25 000 000

dp[i][j] = using i pairs and not building any past point j, max sum
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?