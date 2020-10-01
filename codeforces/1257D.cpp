// https://codeforces.com/problemset/problem/1257/D

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

const int maxn = 200500;

int n, m;
int a[maxn];

// Prefix max of endurance of heroes
int pma[maxn];

pii h[maxn];
int dp[maxn];

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cin >> m;

    for(int i = 1; i <= m; i++) {
        cin >> h[i].fi >> h[i].se;
    }

    sort(h+1, h+m+1, greater<pii>());

    for(int i = 1; i <= m; i++) {
        pma[i] = pma[i-1];
        pma[i] = max(pma[i], h[i].se);
    }

    for(int i = 0; i <= n; i++) {
        dp[i] = LLONG_MAX-500;
    }

    dp[0] = 0;

    int i = 0;
    while(i < n) {
        if(dp[i] == LLONG_MAX-500) continue;

        int lgood = -1; 
        int ma = 0;
        for(int j = i+1; j <= n; j++) {

            ma = max(ma, a[j]);

            // bsearch again for highest endurance hero w power >= ma
            int l = 1;
            int r = m; 
            int lgood2 = -1;

            while(l <= r) {
                int mid = (l + r) / 2;

                if(h[mid].fi >= ma) {
                    lgood2 = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(lgood2 == -1 or pma[lgood2] < j-i) {
                break;
            } else {
                lgood = j;
            }
        }

        if(lgood != -1) {
            dp[lgood] = min(dp[lgood], dp[i]+1);
            i = lgood;
        } else {
            break;
        }
    }


    if(dp[n] == LLONG_MAX-500) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
    }

    // clear everything
    for(int i = 0; i <= n; i++) {
        a[i] = 0;
        dp[i] = LLONG_MAX-500;
    }

    for(int i = 1; i <= m; i++) {
        h[i] = {0, 0};
        pma[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

time complexity: n * logn * logn
57 800 000.0

dp[i] = min heroes used to clear first i monsters

set up max segtree

sort heroes by non increasing power, store prefix max of endurance

for i in 1..n
    bsearch for max clearable with one hero
    update

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?