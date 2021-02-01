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

const int maxn = 200500;

int n;
int a[maxn];
int dp[maxn][2];

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }   

    // 0 = your turn, 1 = friend turn
    dp[n][0] = 0;
    dp[n][1] = a[n];

    if(n-1 >= 1) {
        dp[n-1][0] = 0;
        dp[n-1][1] = a[n-1];
    }

    for(int i = n-2; i >= 1; i--) {
        dp[i][0] = min(dp[i+1][1], dp[i+2][1]);
        dp[i][1] = min(dp[i+1][0]+a[i], dp[i+2][0]+a[i]+a[i+1]);
    }

    cout << dp[1][1] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >>t;

    while(t--) solve();
}

/*

dp[n][2] = ith index, turn

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
