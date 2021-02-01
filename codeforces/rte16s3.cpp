// https://dmoj.ca/problem/rte16s3

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int unsigned int
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 6005;

vector<pii> G[maxn];
int dis[maxn][maxn];
int ree = -1;

void dfs(int node, int par) {
    for(pii adj: G[node]) {
        if(adj.fi == par) continue;

        dis[ree][adj.fi] = dis[ree][node]+adj.se;
        dfs(adj.fi, node);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        G[a].emplace_back(b, w);
        G[b].emplace_back(a, w);
    }

    for(int i = 0; i < n; i++) {
        ree = i;
        dis[ree][i] = 0;
        dfs(i, -1);
    }

    int q;
    cin >> q;

    while(q--) {
        int u, v;
        cin >> u >> v;

        cout << dis[u][v] << endl;
    }
}

/*

36000000
1000000

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?