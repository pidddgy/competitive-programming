// https://codeforces.com/problemset/problem/479/E

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

const int MAXN = 5050;
const int MOD = (int)1e9+7;

int psa[MAXN];
int dp[2][MAXN];

int n, a, b, k;

int mod(int ree) {
    return (ree+MOD)%MOD;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> k;

    // calculate if we have 0 rides left
    for(int i = 1; i <= n; i++) {
        psa[i] = i;
    }

    for(int i = 1; i <= k; i++) {
        int cur = i&1;
        cerr << "currently on " << i << endl;
        for(int j = 1; j <= n; j++) {
            cerr << "on " << j << endl;
            int d = abs(j-b)-1;
            int l = max(1LL, j-d), r = min(n, j+d);
            cerr << l << "," << r << endl;

            // we cannot go to the same floor
            dp[cur][j] = mod((psa[r] - psa[l-1]) - (psa[j]-psa[j-1]));
        }

        // recalculate psa
        for(int j = 1; j <= n; j++) {
            psa[j] = mod(psa[j-1] + dp[cur][j]);
        }
        cerr << endl;
    }

    cout << mod(dp[k&1][a]) << endl;
}

/*

dp[i][j] = when we have i rides left and are on floor j how many possibilities are there?

use flip array



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
