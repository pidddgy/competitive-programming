// https://codeforces.com/contest/1443/problem/C

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

pii a[maxn];
int pre[maxn], suf[maxn];

void solve() {
    int n;
    cin >> n;

    // clear everything
    for(int i = 0; i <= n+50; i++) {
        a[i] = pii(0, 0);
        pre[i] = suf[i] = 0;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i].se;
    }

    sort(a+1, a+n+1);

    // for(int i = 1; i  )

    for(int i = 1; i <= n; i++) {
        pre[i] = max(pre[i-1], a[i].fi);
    }

    for(int i = n; i >= 1; i--) {
        suf[i] = suf[i+1]+a[i].se;
    }

    int ans = LLONG_MAX;
    for(int i = 0; i <= n; i++) {
        ans = min(ans, max(pre[i], suf[i+1]));
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

prefix max[i] + suffix sum[i+1]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
