// https://codeforces.com/contest/615/problem/B 

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define maxn 100500

int n, m;
set<int> G[maxn];
int ans = 0;
int dp[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        // G[min(u, v)].emplace(max(u, v));
        G[u].emplace(v);
        G[v].emplace(u);
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = 1;
        for(int x: G[i]) {
            if(x < i) {
                dp[i] = max(dp[i], dp[x]+1);
            }
        }

        ans = max(ans, dp[i]*(int)G[i].size());
    }

    cout << ans << endl;
}