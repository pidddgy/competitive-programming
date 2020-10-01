// https://dmoj.ca/problem/usaco19decsilvp3

#include <bits/stdc++.h>
using namespace std;
#define cerr cout
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;
int N, M;
string s;
set<int> G[maxn];
int g[maxn], h[maxn], in[maxn], out[maxn], ans[maxn];

int up[maxn][25];

int ind = 1;
int l;
void dfs(int v, int p) {
    // cerr << "on " << v << endl;
    // watch(p)

    in[v] = ++ind;
    up[v][0] = p;

    g[v] = g[p];
    h[v] = h[p];

    if(s[v] == 'G') g[v]++;
    else h[v]++;

    for(int i = 1; i <= l; i++) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(int adj: G[v]) {
        if(adj != p) {
            // cerr << "pushing " << adj << "," << v << endl;
            dfs(adj, v);
        }
    }

    out[v] = ++ind;
}

bool isAncestor(int u, int v) {
    return (in[u] <= in[v] and out[u] >= out[v]);
}

int lca(int u, int v) {
    if(isAncestor(u, v)) return u;
    if(isAncestor(v, u)) return v;

    for(int i = l; i >= 0; i--) {
        if(!isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }

    return up[u][0];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> s;

    s = "."+s;

    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    l = ceil(log2(N));
    dfs(1, 1);
    
    for(int i = 1; i <= M; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        
        int v = lca(a, b);

        // cerr << "lca of " << a << "," << b << " is " << v << endl;
        int gcnt = g[a] + g[b] - 2*g[v] + (s[v]=='G');
        int hcnt = h[a] + h[b] - 2*h[v] + (s[v]=='H');

        if(c == 'G') {
            ans[i] = gcnt>0;
        } else {
            ans[i] = hcnt>0;
        }
    }

    for(int i = 1; i <= M; i++) {
        cout << ans[i];
    }
    cout << endl;
}
