// https://codeforces.com/problemset/problem/1083/A

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

const int maxn = 300500;

int n, ans = 0;
int w[maxn];

// .first = destination, .se = cost
set<pii> G[maxn];

int dfs(int v, int par) {
    int ma = 0, ma2 = 0;
    for(pii to: G[v]) {
        if(to.fi == par) continue;

        int val = dfs(to.fi, v) - to.se;

        if(val > ma) {
            ma2 = ma;
            ma = val;
        } else if(val > ma2) {
            ma2 = val;
        }
    }

    ans = max(ans, w[v] + ma + ma2);
    return w[v] + ma;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        G[u].emplace(pii(v, c));
        G[v].emplace(pii(u, c));
    }

    dfs(1, -1);

    cout << ans << endl;
}

/*

calculate once with bfs then use tree rerooting dp

store gasoline and lowest point

when rerooting:
    we have an edge from current node to child
    add edge value to lowest point of child
    subtract edge value from the lowest point of the parent
ok reeeee rerooting doesnt really work because we would need to extend the leaves outward after each reroot

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
