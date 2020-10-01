// https://codeforces.com/contest/1081/problem/D

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
    
}

struct Edge {
    int u, v, cost;
    Edge(int uu, int vv, int costt) {
        u = uu;
        v = vv;
        cost = costt;
    }
};

struct Compare {
    bool operator()(Edge &l, Edge &r) {
        return l.cost < r.cost; 
    }
};

const int maxn = 100500;
// .fi = dest, .se = cost;
vector<pii> G[maxn];
vector<Edge> edges;
int disj[maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    else return disj[v] = findp(disj[v]);
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    disj[c] = d;
}

// number of special nodes in this subtree
int dp[maxn];
int x[maxn];
bool special[maxn];

int dfs(int v, int par) {
    int sum = 0;
    for(pii e: G[v]) {
        if(e.fi != par) {
            sum += dfs(e.fi, v);
        }
    }
    sum += special[v];

    dp[v] = sum;
    return sum;
}

int ans = 0;
void dfs2(int v, int par) {
    for(pii e: G[v]) {
        if(e.fi != par) {
            if(dp[e.fi]) {
                ans = max(ans, e.se);
                dfs2(e.fi, v);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 1; i <= n; i++) disj[i] = i;

    for(int i = 1; i <= k; i++) {
        cin >> x[i];
        special[x[i]] = true;
    }

    for(int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        edges.emplace_back(u, v, c);
    }

    sort(all(edges), Compare());

    for(Edge e: edges) {
        if(findp(e.u) != findp(e.v)) {
            merge(e.u, e.v);

            G[e.u].emplace_back(e.v, e.cost);
            G[e.v].emplace_back(e.u, e.cost);
        }
    }

    // dfs(1, -1);
    for(int i = 1; i <= n; i++) {
        if(special[i]) {
            // cerr << "dfs from " << i << endl;
            dfs(i, -1);
            dfs2(i, -1);
            break;
        }
    }

    for(int i = 1; i <= k; i++) {
        cout << ans << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
