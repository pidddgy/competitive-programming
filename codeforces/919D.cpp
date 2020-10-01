// https://codeforces.com/problemset/problem/919/D

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

const int maxn = 300500;

int n, m;
string s;

set<int> G[maxn];
int vis[maxn];
int dp[maxn][50];

void dfs(int v) {
    vis[v] = 1;
    for(int to: G[v]) {
        if(vis[to] != 2) {
            if(vis[to] == 1) {
                cout << -1 << endl;
                exit(0);
            } else {
                dfs(to);
            }
        }

        for(int i = 0; i < 26; i++) {
            dp[v][i] = max(dp[v][i], dp[to][i]);
        }
    }

    vis[v] = 2;
    dp[v][s[v]-'a']++;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    cin >> s;

    s = "."+s;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
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
