// https://codeforces.com/contest/1406/problem/C

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


// #define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

const int maxn = 100500;

int n;
vector<vector<int>> G(maxn);

// https://codeforces.com/blog/entry/57593
vector<int> Centroid(const vector<vector<int>> &g) {
    vector<int> centroid;
    vector<int> sz(n+2);
    function<void (int, int)> dfs = [&](int u, int prev) {
            // cerr << "currently on " << u << endl;
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : g[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    // dfs(0, -1);
    dfs(1, -1);
    return centroid;
}


void solve() {
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }    

    vector<int> centroids = Centroid(G);

    if(centroids.size() == 1) {
        for(int i = 1; i <= n; i++) {
            if(G[i].size()) {
                cout << i << " " << G[i][0] << endl;
                cout << i << " " << G[i][0] << endl;
                break;
            }
        }
    } else {
        int v1 = centroids[0], v2 = centroids[1];

        for(int x: G[v1]) {
            if(x != v2) {
                cout << v1 << " " << x << endl;
                cout << x << " " << v2 << endl;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        G[i].clear();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

wee guessforces time

find the two centroids of tree

attach the biggest subtree to the other

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
