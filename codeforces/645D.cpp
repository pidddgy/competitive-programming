// https://codeforces.com/problemset/problem/645/D

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

int n, m;

// list of all edges
pii edges[maxn];

// in graph format
vector<int> G[maxn];

int topoind = n;
int topo[maxn];
bool vis[maxn];
int dp[maxn];

void dfs(int node) {
    vis[node] = true;
    for(int to: G[node]) {
        if(!vis[to]) {
            dfs(to);
        }
    }

    topo[topoind--] = node;
}

bool ok(int x) {
    cerr << "trying " << x << endl;
    // clear everything
    topoind = n;
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        dp[i] = 1;
        vis[i] = false;    
    }
    
    for(int i = 1; i <= x; i++) {
        G[edges[i].fi].emplace_back(edges[i].se);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    // i is in topological order
    int ma = 0;
    for(int i = 1; i <= n; i++) {
        cerr << topo[i] << " ";
        int cur = topo[i];
        for(int to: G[cur]) {
            dp[to] = max(dp[to], dp[cur]+1);
        }
        ma = max(ma, dp[cur]);
    }
    cerr << endl;

    return (ma == n);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        cin >> edges[i].fi >> edges[i].se;
    }

    int l = 1, r = m;
    int lgood = -1;
    while(l <= r) {
        int mid = (l + r) / 2;

        if(ok(mid)) {
            r = mid-1;
            lgood = mid;
        } else {
            l = mid+1;
        }
    }

    cout << lgood << endl;
}

/*

binary search for min number of edges needed

when checking:
    go from left to right of topological sort
    dp[i] = max length ending in node i





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
