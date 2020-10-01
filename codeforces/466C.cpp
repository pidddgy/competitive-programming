// https://codeforces.com/problemset/problem/466/C

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

const int maxn = (int)5e5+5;

int n;
int a[maxn];
int psa[maxn];
int dp[4][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int tot = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1] + a[i];
        tot += a[i];
    }

    for(int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    if(tot % 3) {
        cout << 0 << endl;
        return 0;
    }

    int per = tot / 3;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) {
            if(psa[j] == i*per) {
                dp[i][j] = dp[i-1][j-1];
            }
            cerr << dp[i][j] << " ";
            dp[i][j] += dp[i][j-1];
        }
        cerr << endl;
    }

    cout << dp[3][n] - dp[3][n-1] << endl;
}

/*

let sum of each subarray be total sum / 3
calculate number of ways to split into sum with a 0 at end, 2*sum with sum, so on

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
