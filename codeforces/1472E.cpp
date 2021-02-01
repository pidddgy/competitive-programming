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

int n;
vector<pair<pii, int>> a;
int ans[maxn];

struct Compare {
    bool operator()(pair<pii, int> l, pair<pii, int> r) {
        return l.fi < r.fi;
    }
};

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) ans[i] = -1;

    a.clear();

    for(int i = 1; i <= n; i++) {
        int w, h;
        cin >> w >> h;

        a.emplace_back(pii(w, h), i);
        a.emplace_back(pii(h, w), i);

    }

    sort(all(a), Compare());

    pii mi = pii(1e18, -1);
    pii nxt = pii(1e18, -1);
    for(int i = 0; i < sz(a); i++) {
        cerr << a[i].fi.fi << " " << a[i].fi.se << " " << a[i].se << endl;
        cerr << mi.fi << " " << mi.se << endl;

        if(i > 0 and a[i].fi.fi > a[i-1].fi.fi) {
            cerr << "update" << endl;
            mi = min(mi, nxt);
            nxt = pii(1e18, -1);
        }
        cerr << endl;

        if(mi.fi < a[i].fi.se)
            ans[a[i].se] = mi.se;

        nxt = min(nxt, pii(a[i].fi.se, a[i].se));
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();   
}

/*

compress
get min y encountered
push rotated

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?