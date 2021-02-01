// https://codeforces.com/contest/1183/problem/G

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
pii a[maxn];

bool cmp(pii &l, pii &r) {
    if(l.fi+l.se == r.fi+r.se) return l.se>r.se;

    return (l.fi+l.se) > (r.fi+r.se);
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;

        if(y == 0) {
            a[x].fi++;
        } else {
            a[x].se++;
        }
    }

    sort(a+1, a+n+1, cmp);

    for(int i = 1; i <= n; i++) {
        cerr << a[i].fi << " " << a[i].se << endl;
    }

    int cur = 2*n;

    int ans = 0;
    int ones = 0;
    for(int i = 1; i <= n; i++) {
        while(cur > a[i].fi+a[i].se) cur--;
        if(cur <= 0) break;

        cerr << "take " << cur << " of " << i << endl;
        ans += cur;
        ones += min(cur, a[i].se);

        cur--;
    }

    cerr << "ans:" << endl;
    cout << ans << " " << ones << endl;

    // clear everything
    for(int i = 1; i <= n; i++) {
        a[i].fi = a[i].se = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--) {
        solve();
    }
}

/*

int a[n][2]

find max value possible, then optimize for 1s

8
1 0
2 0
2 0
3 0
4 1
4 1
5 1
6 1

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
