// https://codeforces.com/contest/853/problem/B

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
    
}

const int maxn = 100500;
const int maxd = 1005000;
const int INF = 1e11;

vector<pii> go[maxd], ret[maxd];
int l[maxd], r[maxd];
int mi[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) {
        int d, f, t, c;
        cin >> d >> f >> t >> c;

        if(t == 0) {
            go[d].emplace_back(f, c);
        } else {
            ret[d].emplace_back(t, c);
        }
    }

    for(int i = 1; i <= n; i++) mi[i] = INF;
    int cur = INF*n;
    for(int i = 0; i <= 1e6; i++) {
        if(i <= 10) cerr << "on " << i << endl;
        for(pii x: go[i]) {
            cerr << x.fi << " " << x.se << endl;
            if(mi[x.fi] > x.se) {
                int reduced = mi[x.fi]-x.se;
                cur -= reduced;
                cerr << "will reduce by " << reduced << endl;

                mi[x.fi] = x.se;
            }
        }

        if(i <= 10)
        watch(cur)
        l[i] = cur;
    }

    for(int i = 1; i <= n; i++) mi[i] = INF;
    cur = INF*n;
    for(int i = 1e6; i >= 0; i--) {
        for(pii x: ret[i]) {
            if(mi[x.fi] > x.se) {
                int reduced = mi[x.fi]-x.se;
                cur -= reduced;

                mi[x.fi] = x.se;
            }
        }

        r[i] = cur;
    }

    int ans = 1e18;
    for(int i = 1; i+k <= 1e6; i++) {
        ans = min(ans, l[i-1] + r[i+k]);
    }

    if(ans > INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

/*

do stuff to find the min cost of getting into 0 before day i (careful for off by one error)

for now, only take into account "going in" edges, sorted in order by departure time
keep an array of changes
for each person:
    maintain current cost (init == INF)
    for each edge:
        if cost is less than current cost
            update change at index of that day


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
