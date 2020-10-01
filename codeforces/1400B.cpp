// https://codeforces.com/contest/1400/problem/B

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
    int p, f, cnts, cntw, s, w;
    cin >> p >> f >> cnts >> cntw >> s >> w;

    if(s > w) {
        swap(s, w);
        swap(cnts, cntw);
    }

    int ans = 0;
    for(int i = 0; i <= cnts; i++) {
        if(i * s > p) break;
        int loc = 0;

        int rems = cnts, remw = cntw;
        int capacity = p;

        // take sword
        int take = min(rems, i);
        capacity -= take*s;
        loc += take;
        rems -= take;

        // take war axe
        take = min(remw, capacity/w);
        loc += take;
        remw -= take;

        capacity = f;

        // take sword
        take = min(rems, capacity/s);
        capacity -= take*s;
        loc += take;

        // take war axe
        take = min(remw, capacity/w);
        loc += take;

        ans = max(ans, loc);
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

brute force on number of swords you take. number of axes you take can be calculated in O(1)

follower just takes whatever cheaper first

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
