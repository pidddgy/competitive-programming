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

const int maxn = 200500;

int n, m;
int d[maxn];

vector<int> G[maxn];

// dp[i][j] = node, used one operation or not
int dp[maxn][2];
bool vis[maxn];


void dfs(int v) {
    vis[v] = true;
    // base case
    dp[v][0] = d[v];

    for(int to: G[v]) {
        if(!vis[to]) dfs(to);

        // real edge?
        if(d[v] < d[to]) {
            dp[v][0] = min(dp[v][0], dp[to][0]);
            dp[v][1] = min(dp[v][1], dp[to][1]);
        } else {
            dp[v][1] = min(dp[v][1], dp[to][0]);
        }
    }
    
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;

        G[u].emplace_back(v);
    }

    for(int i = 1; i <= n; i++) {
        d[i] = 1e18;
        dp[i][0] = dp[i][1] = 1e18;
        vis[i] = false;
    }

    d[1] = 0;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int to: G[S]) {
            if(d[to] > d[S]+1) {
                Q.push(to);
                d[to] = d[S]+1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i <= n; i++) vis[i] = false;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++) {
        cerr << dp[i][0] << " " << dp[i][1] << endl;
    }

    for(int i = 1;i <= n; i++) {
        cout << min(dp[i][0], dp[i][1]) << " ";
    }
    cout << endl;

    // clear
    for(int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 0;
        G[i].clear();
        vis[i] = false;
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

form dag, "real edge" only exists if d[u] < d[v]
dag dp

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
