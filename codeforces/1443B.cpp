// https://codeforces.com/contest/1443/problem/B

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
    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    int n = sz(s);

    s = "."+s;

    vector<pii> v;
    int l = -1, r = -1;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0' and l != -1 and r != -1) {
            v.emplace_back(l, r);
            l = -1;
            r = -1;
        }
        if(s[i] == '1' and l == -1) {
            l = i;
        }

        if(s[i] == '1') r = i;
    }

    if(l != -1) {
        v.emplace_back(l, n);
    }

    // for(pii x: v) {
    //     cerr << x.fi << " " << x.se << endl;
    // }
    int ans = sz(v)*a;

    // better to join with i-1?
    for(int i = 1; i < sz(v); i++) {
        int between = v[i].fi-v[i-1].se-1;

        if(between*b < a) {
            ans -= a;
            ans += between*b;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

start with doing all induvidually

join all the ones that would give lower cost


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
