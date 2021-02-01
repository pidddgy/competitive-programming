// https://dmoj.ca/problem/oly20practice92

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)5e4+50;
int n, l;
vector<int> adj[maxn];
int dep[maxn];
bool vis[maxn];

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> q;
    
    // assert(n <= 1e4);

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

        // assert(p < maxn);
        // assert(i < maxn);
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    queue<int> Q;
    Q.push(0);

    dep[0] = 1;
    vis[0] = true;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int to: adj[S]) {
            if(!vis[to]) {
                vis[to] = true;
                dep[to] = dep[S]+1;
                Q.push(to);
            }
        }
    }

    preprocess(0);

    // while(q--) {
    //     int l, r, x;

    //     cin >> l >> r >> x;

    //     int sum = 0;
    //     for(int i = l; i <= r; i++) {
    //         sum += dep[lca(i, x)];
    //     }

    //     cout << sum << endl;
    // }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
