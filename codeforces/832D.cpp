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

vector<int> G[maxn];
int dep[maxn];
int up[35][maxn];

int tin[maxn];
int tout[maxn];

int n, q;
int timer = 0;

int ancestor(int u, int v) {
    return (tin[u] <= tin[v] and tout[u] >= tout[v]);
}

int lca(int u, int v) {
    if(ancestor(u, v)) return u;
    if(ancestor(v, u)) return v;

    // cerr << "lca of " << u << " " << v << endl;

    for(int i = 20; i >= 0; i--) {
        if(up[i][u] != -1 and !ancestor(up[i][u], v)) {
            u = up[i][u];
        }
    }

    assert(up[0][u] != -1);
    return up[0][u];
}

// number of nodes on path from u -> v
int pathlen(int u, int v) {
    // cerr << u << " " << v << endl;
    return dep[u] + dep[v] - 2*dep[lca(u, v)] + 1;
}

void dfs(int v, int par) {
    tin[v] = ++timer;

    for(int to: G[v]) {
        if(to == par) continue;

        cerr << "going to " << to << " from " << v << endl;
        up[0][to] = v;
        dep[to] = dep[v]+1;
        dfs(to, v);
    }
    tout[v] = ++timer;
}

int f(int s, int t, int f) {
    return (pathlen(s, f) + pathlen(t, f) - pathlen(s, t) + 1)/2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        G[i].emplace_back(p);
        G[p].emplace_back(i);
    }

    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j < maxn; j++) {
            up[i][j] = -1;
        }
    }

    dep[1] = 1;
    dfs(1, -1);

    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= n; j++) {
            if(up[i-1][j] != -1)
                up[i][j] = up[i-1][up[i-1][j]];
        }
    }

    while(q--) {
        vector<int> v(3);

        cin >> v[0] >> v[1] >> v[2];

        sort(all(v));

        int ans = -1e18;
        watch(ans)
        do {
            int val = f(v[0], v[1], v[2]);
            cerr << v[0] << " " << v[1] << " " << v[2] << endl;
            watch(val)
            ans = max(ans, val);
        } while(next_permutation(all(v)));

        cout << ans << endl;
        cerr << endl;
    }
}

/*

(d(s, f) + d(t,f) - d(s, t) + 1) / 2


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
