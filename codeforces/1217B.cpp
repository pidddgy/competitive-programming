// https://codeforces.com/contest/1217/problem/B

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

const int maxn = 105;

pii a[maxn];

bool cmp(pii &l, pii &r) {
    return (l.fi-l.se) > (r.fi-r.se);
}

void solve() {
    int n, x;
    cin >> n >> x;

    int ma = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        ma = max(ma, a[i].fi);
    }

    sort(a+1, a+n+1, cmp);

    int val = (a[1].fi-a[1].se);
    int need = x-ma;

    if(val <= 0) {
        if(need > 0) {
            cout << -1 << endl;
        } else {
            cout << 1 << endl;
        }

        return;
    }

    watch(val)

    if(need < 0) {
        cout << 1 << endl;
    } else {
        cout << ((need+val-1)/val)+1 << endl;
    }

    for(int i = 1; i <= n; i++) {
        a[i] = pii(0, 0);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

use the blow with the biggest difference until the number of heads is <= the blow with biggest d[i]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
