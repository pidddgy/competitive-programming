// https://codeforces.com/contest/1385/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define eb emplace_back
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int maxn = 200500;

int vis[maxn], ind[maxn];
vi path, topo;
vector<vi> cycles;
vi G[maxn];
int n, m;

void reset() {
    topo.clear();
    cycles.clear();
    for(int i = 0; i <= n; i++) {
        vis[i] = 0;
        ind[i] = 0;
        G[i].clear();
    }
}

void dfs(int v) {
    if(cycles.size()) return;
    vis[v] = 1;
    path.eb(v);

    for(int to: G[v]) {
        if(vis[to] != 2) {
            if(vis[to] == 1) {
                cycles.eb(vi());

                for(int i = path.size()-1; path[i] != to; i--) {
                    cycles.back().eb(path[i]);
                }
                cycles.back().eb(to);
            } else {
                dfs(to);
            }
        }
    }
    
    topo.push_back(v);
    path.pop_back();
    vis[v] = 2;
}

void solve() {
    cin >> n >> m;

    vector<vi> edges;

    for(int i = 1; i <= m; i++) {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 1) {
            G[u].eb(v);
        }

        edges.emplace_back(vi({t, u, v}));
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    reverse(topo.begin(), topo.end());

    for(int i = 0; i < topo.size(); i++) {
        // cerr << topo[i] << " ";
        ind[topo[i]] = i;
    }
    // cerr << endl;

    // for(int i = 1; i <= n; i++) {
    //     cerr << ind[i] << " ";
    // }
    // cerr << endl;


    if(cycles.empty()) {
        cout << "YES" << endl;
        for(vi x: edges) {
            if(x[0] == 1) {
                cout << x[1] << " " << x[2] << endl;
            } else {
                vector<pii> ans = {{ind[x[1]], x[1]}, {ind[x[2]], x[2]}};
                sort(ans.begin(), ans.end());

                cout << ans[0].se << " " << ans[1].se << endl;
            }
        }
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
        reset();
    }
}