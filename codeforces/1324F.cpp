// https://codeforces.com/problemset/problem/1324/F

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

const int maxn = 200500;

int a[maxn], ans[maxn], dp[maxn];
vector<int> G[maxn];

void dfs(int v, int par = -1) {
    dp[v] = a[v];
    for(int to: G[v]) {
        if(to != par) {
            dfs(to, v);
            dp[v] += max(0LL, dp[to]);
        }
    }
}

void dfs2(int v, int par = -1) {
    ans[v] = dp[v];

    for(int to: G[v]) {
        if(to != par) {
            dp[v] -= max(0LL, dp[to]);
            dp[to] += max(0LL, dp[v]);
            dfs2(to, v);
            dp[to] -= max(0LL, dp[v]);
            dp[v] += max(0LL, dp[to]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        // convert into cost
        if(a[i] == 0) a[i] = -1;
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1);
    dfs2(1);

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
