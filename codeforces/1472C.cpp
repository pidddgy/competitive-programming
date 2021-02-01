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

int a[maxn];
int dp[maxn];

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i <= n; i++) a[i] = dp[i] = 0;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if(i+a[i] > n) dp[i] = a[i];
        else dp[i] = a[i]+dp[i+a[i]];

        ans = max(ans, dp[i]);
    }    

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
