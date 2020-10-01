// https://codeforces.com/contest/436/problem/C

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

const int maxk = 1005;

struct Edge {
    int u, v, weight;

    Edge(int uu, int vv, int weightt) {
        u = uu;
        v = vv;
        weight = weightt;
    }
};

struct Compare {
    bool operator()(Edge &l, Edge &r) {
        return l.weight < r.weight;
    }
};

int par[maxk];
string a[maxk];
vector<Edge> edges;
vector<int> G[maxk];
bool vis[maxk];

int findp(int v) {
    if(par[v] == v) return v;
    else return par[v] = findp(par[v]);
}

void merge(int v1, int v2) {
    int p1 = findp(v1), p2 = findp(v2);

    par[p1] = p2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxk; i++) par[i] = i;

    int n, m, k, w;
    cin >> n >> m >> k >> w;

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            string s;
            cin >> s;

            a[i] += s;
        }
    }

    for(int i = 1; i <= k; i++) {
        edges.emplace_back(i, 0, n*m);
        for(int j = 1; j <= k; j++) {
            if(i == j) continue;

            int cost = 0;
            for(int l = 0; l < n*m; l++) {
                if(a[i][l] != a[j][l]) cost++;
            }

            edges.emplace_back(i, j, cost*w);
            edges.emplace_back(j, i, cost*w);
        }
    }

    sort(all(edges), Compare());
    int cost = 0;
    int used = 0;
    for(Edge e: edges) {
        if(findp(e.u) != findp(e.v)) {
            merge(e.u, e.v);
            G[e.u].emplace_back(e.v);
            G[e.v].emplace_back(e.u);
            cost += e.weight;
            used++;
        }

        if(used == k) break;
    }

    queue<int> Q;
    Q.push(0);
    vis[0] = true;

    cout << cost << endl;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(vis[adj]) continue;
            vis[adj] = true;
            Q.push(adj);
            cout << adj << " " << S << endl;
        }
    }

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
