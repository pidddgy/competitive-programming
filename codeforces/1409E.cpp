// https://codeforces.com/problemset/problem/1409/E

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

int x[maxn], y[maxn];
int pma[maxn];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    sort(x+1, x+n+1);

    int ans = 0;
    int ma = 0;
    // find leftmost
    for(int i = 1; i <= n; i++) {
        int l = 1;
        int r = i;
        int lgood = -1;

        while(l <= r) {
            int mid = (l+r)/2;

            if(x[i]-x[mid] <= k) {
                lgood = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        ans = max(ans, i-lgood+1 + pma[lgood-1]);

        pma[i] = max(pma[i-1], i-lgood+1);
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
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
