// https://codeforces.com/problemset/problem/700/B

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

bool uni[maxn];
int dp[maxn];
int n, k;
vector<int> G[maxn];
int ans = 0;

int dfs(int v, int par) {
    int sum = uni[v];
    for(int to: G[v]) {
        if(to == par) continue;

        sum += dfs(to, v);
    }

    if(par != -1) {
        ans += min(dp[v], 2*k-dp[v]);
    }

    dp[v] = sum;
    return dp[v];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= 2*k; i++) {
        int x;
        cin >> x;

        uni[x] = true;
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);
    ans = 0;
    dfs(1, -1);

    cout << ans << endl;
}

/*

get contribution of each edge

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
