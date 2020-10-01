// https://codeforces.com/problemset/problem/274/B

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

const int maxn = 100500;

int n;
vector<int> G[maxn];
int v[maxn];
int add[maxn], sub[maxn];

void dfs(int node, int par) {
    for(int to: G[node]) {
        if(to == par) continue;

        dfs(to, node);

        add[node] = max(add[node], add[to]);
        sub[node] = max(sub[node], sub[to]);
    }

    v[node] += add[node];
    v[node] -= sub[node];

    if(v[node] > 0) {
        sub[node] += v[node];
    } else if(v[node] < 0) {
        add[node] += -v[node];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    dfs(1, -1);

    cout << add[1] + sub[1] << endl;
}

/*

start at 1

think about cost to "fix" a certain subtree

after we fix a certain node's children, what will current value be?

1 will take the maximum of all costs of children 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
