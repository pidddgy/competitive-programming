// https://codeforces.com/contest/1405/problem/D

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

const int maxn = 100500;
vector<int> G[maxn];
int dis[maxn];

int n, a, b, da, db;

int bfs(int v) {
    for(int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }

    queue<int> Q;
    Q.push(v);
    dis[v] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(dis[adj] > dis[S]+1) {
                dis[adj] = dis[S]+1;
                Q.push(adj);
            }
        }
    }

    int ma = INT_MIN;
    int ret = -1;
    for(int i = 1; i <= n; i++) {
        if(dis[i] > ma) {
            ma = dis[i];
            ret = i;
        }
    }

    assert(ret != -1);
    return ret;
}

void solve() {
    cin >> n >> a >> b >> da >> db;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    bfs(a);
    int endpoint = bfs(1);
    int diameter = dis[bfs(endpoint)];

    watch(diameter)
    watch(da*2+1)
    if(min(diameter, db) >= da*2+1) {
        bfs(a);

        if(dis[b] <= da) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
    // clear everything

    for(int i = 1; i <= n; i++) {
        G[i].clear();
        dis[i] = INT_MAX;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) solve();
}

/*

check if min(diameter, bob's distance) is big enough to "jump over" alice


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
