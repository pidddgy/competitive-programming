// https://codeforces.com/contest/1133/problem/F1

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;
int n, m;
set<int> G[maxn];
vector<pii> edges;

int par[maxn];

int findp(int n) {
    if(par[n] != n) {
        return par[n] = findp(par[n]);
    }

    return n;
}

void merge(int x, int y) {
    int a = findp(x);
    int b = findp(y);

    par[a] = b;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) par[i] = i;

    int ma = 0;
    int manode = -1;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);

        for(int x: set<int>({u, v})) {
            if(G[x].size() > ma) {
                ma = G[x].size();
                manode = x;
            }
        }

        edges.emplace_back(u, v);
    }

    vector<pii> ans;
    for(int adj: G[manode]) {
        merge(manode, adj);
        ans.emplace_back(manode, adj);
    }

    for(pii x: edges) {
        if(findp(x.fi) != findp(x.se)) {
            merge(x.fi, x.se);
            ans.emplace_back(x.fi, x.se);
        }
    }

    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }    
}