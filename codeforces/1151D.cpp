// https://codeforces.com/contest/1151/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

struct Compare {
     bool operator()(pii &l, pii &r) {
        int lval = l.se - l.fi;
        int rval = r.se - r.fi;

        return lval < rval;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    pii a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a+1, a+n+1, Compare());

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        // cout << a[i].fi << " " << a[i].se << endl;
        ans += (a[i].fi * (i-1)) + (a[i].se * (n-i));
    }

    cout << ans << endl;
}