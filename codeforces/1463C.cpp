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

const int maxn = 100500;


int t[maxn], p[maxn];

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    t[n+1] = 1e18;

    int ans = 0;
    int b = 0;
    int last = 0;
    int to = 0;
    int dir = 0;
    int e = 0;

    for(int i = 1; i <= n; i++) {
        if(t[i] >= b) {
            b = t[i] + abs(to-p[i]);
            last = to;
            to = p[i];
            
            if(last < to) dir = 1;
            if(last == to) dir = 0;
            if(last > to) dir = -1;

            e = 0;
        }

        int have = t[i+1]-t[i];
        int cur = last+(e*dir);

        bool ok = true;

        if(dir == 1 and cur > p[i]) ok = false;
        if(dir == -1 and cur < p[i]) ok = false;

        int use = min({have, abs(cur-p[i]), abs(cur-to)});

        if(ok)
        if(cur + use*dir == p[i]) {
            cerr << "ok" << endl;
            ans++;
        }

        e += t[i+1]-t[i];
    }
    cout << ans << endl;

    for(int i = 1; i <= n+5; i++) {
        t[i] = p[i] = 0;
    }
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

maintain last, to, elapsed
check if p is within last, to
we have y time before next command




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?