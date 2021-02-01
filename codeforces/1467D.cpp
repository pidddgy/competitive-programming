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

const int MOD = (int)1e9+7;

int n, k, q;

int mod(int num) {
    return (num+MOD)%MOD;
}

const int maxn = 6000;

int dp[maxn][maxn];
int ways[maxn];
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> q;

    for(int i = 1; i <= n; i++) {
        dp[0][i] = 1;
    }

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            dp[i][j] = mod(dp[i-1][j-1] + dp[i-1][j+1]);
        }
    }

    for(int i = 0; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            // how many ways to get to j in i moves * how many ways to spend k-i moves from j
            ways[j] += mod(dp[i][j] * dp[k-i][j]);
            ways[j] = mod(ways[j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += mod(a[i]*ways[i]);
        ans = mod(ans);
    }

    while(q--) {
        int i, v;
        cin >> i >> v;

        ans -= mod(a[i]*ways[i]);
        ans = mod(ans);

        a[i] = v;

        ans += mod(a[i]*ways[i]);
        ans = mod(ans);

        cout << ans << endl;
    }
}

/*

how many subarrays of size k does this element belong to?
number of subarrays


dp[i][j] = how many ways to end up at index j in i moves?
dp2[i][j] = how many ways to spend i moves from index j?



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
