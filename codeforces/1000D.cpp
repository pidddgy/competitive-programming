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

const int maxn = (int)1e3+500;
const int MOD = 998244353;

int n;
int a[maxn];
int dp[maxn];
int c[maxn][maxn];

int mod(int num) {
    return (num+MOD)%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // choose table
    for(int i = 0; i <= 1e3; i++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++) {
            c[i][j] = mod(c[i-1][j] + c[i-1][j-1]);
        }
    }

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[n+1] = 1;
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        if(a[i] <= 0) continue;

        for(int j = i+a[i]+1; j <= n+1; j++) {
            dp[i] += mod(c[j-i-1][a[i]]*dp[j]);
            dp[i] = mod(dp[i]);
        }

        ans += dp[i];
        ans = mod(ans);
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
