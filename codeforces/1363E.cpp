// https://codeforces.com/contest/1363/problem/E

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

const int maxn = 200500;

int a[maxn], b[maxn], c[maxn];
// "prefix min" on tree
int mi[maxn];
int cnta[maxn], cntb[maxn];

vector<int> G[maxn];

void dfs(int v, int par) {
    mi[v] = min(mi[v], a[v]);
    for(int to: G[v]) {
        if(to == par) continue;

        mi[to] = min(mi[to], mi[v]);
        dfs(to, v);
    }
}

int ans = 0;
pii dfs2(int v, int par) {
    pii res = {0, 0};

    if(b[v] == 0 and c[v] == 1) res.fi++;
    if(b[v] == 1 and c[v] == 0) res.se++;

    for(int to: G[v]) {
        if(to == par) continue;

        pii c = dfs2(to, v);

        res.fi += c.fi;
        res.se += c.se;
    }

    if(mi[v] == a[v]) {
        int take = min(res.fi, res.se);
        ans += take*2*a[v];

        res.fi -= take;
        res.se -= take;
    }

    if(v == 1 and (res.fi or res.se)) {
        cout << -1 << endl;
        exit(0);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++) mi[i] = 1e12;
    dfs(1, -1);
    dfs2(1, -1);

    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        cerr << mi[i] << " ";
    }
    cerr << endl;
}

/*

only do pairs of 2

type a = 01
type b = 10

pair as many a, b as possible

do prefix min but on a tree

if prefix min[i] = i, pair all now



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
