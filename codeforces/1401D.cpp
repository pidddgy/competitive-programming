// https://codeforces.com/problemset/problem/1401/D

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

const int MAXN = 100500;
const int MOD = (int)1e9+7;

int n, m;
deque<int> dq;
vector<int> G[MAXN];
vector<pii> edges;
int dp[MAXN];

int dfs(int node, int par = -1) {
    int sum = 1;
    for(int to: G[node]) {
        if(to == par) continue;

        sum += dfs(to, node);
    }

    dp[node] = sum;
    return dp[node];
}

int contribution(pii edge) {
    int v;

    if(dp[edge.fi] < dp[edge.se]) v = edge.fi;
    else v = edge.se;

    return (dp[v]) * (n-dp[v]);
}

bool compare(pii &l, pii &r) {
    return contribution(l) > contribution(r);
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
        edges.emplace_back(u, v);
    }

    cin >> m;

    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        dq.emplace_back(x);   
    }

    sort(all(dq), greater<int>());
    while(sz(dq) > n-1) {
        int x = dq.front(); dq.pop_front();
        int y = dq.front(); dq.pop_front();

        dq.push_front((x*y) % MOD);
    }

    while(sz(dq) < n-1) {
        dq.emplace_back(1);
    }

    for(int &x: dq) {
        x %= MOD;
    }

    dfs(1);

    for(int i = 1; i <= n; i++) {
        cerr << dp[i] << " ";
    }
    cerr << endl;

    for(int x: dq) {
        cerr << x << " ";
    }
    cerr << endl;

    sort(all(edges), compare);

    int ans = 0;
    for(pii e: edges) {
        watch(contribution(e))
        cerr << e.fi << " " << e.se << endl;
        ans += contribution(e)*dq.front();
        ans %= MOD;
        dq.pop_front();
    }

    cout << ans << endl;

    // clear everything
    dq.clear();
    edges.clear();
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        dp[i] = 0;
    }


}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*
we want to put a prime factor on each edge

root tree from 1 and dfs on how many nodes are in this node subtree including the current node

find contribution of each edge
for each edge
    take the minimum (this is the node closer to the bottom)
    this edge contributes (dp[x]-1) * n-dp[x]
    first is bottom, second is top

sort edges by how much they contribute
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
