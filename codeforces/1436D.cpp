// https://codeforces.com/contest/1436/problem/D

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
vector<int> G[maxn];
int a[maxn];

int leaves[maxn], dp[maxn], sum[maxn];

void dfs(int v) {
    if(G[v].empty()) leaves[v]++;
    sum[v] += a[v];

    for(int to: G[v]) {
        dfs(to);
        
        sum[v] += sum[to];
        leaves[v] += leaves[to];

        dp[v] = max(dp[v], dp[to]);
    }

    dp[v] = max(dp[v], (sum[v]+leaves[v]-1)/leaves[v]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;

        G[p].emplace_back(i);
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dfs(1);

    cout << dp[1] << endl;
}

/*

max in any subtree

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
