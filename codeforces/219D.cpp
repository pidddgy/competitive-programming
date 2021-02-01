// https://codeforces.com/problemset/problem/219/D

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

const int maxn = 200500;

set<pii> G[maxn];
bool vis[maxn];
int dp[maxn];
int init = 0;

void clearVis() {
    for(int i = 0; i < maxn; i++) vis[i] = false;
}

void dfs(int v) {
    vis[v] = true;
    for(pii e: G[v]) {
        int to;
        if(e.fi == v) to = e.se;
        else if(e.se == v) to = e.fi;
        else assert(false);

        if(!vis[to]) {
            if(to == e.fi) {
                init++;
                cerr << to << " is first type" << endl;
                dp[to] = dp[v] - 1;
            } else {
                cerr << to << " is second type" << endl;
                dp[to] = dp[v] + 1;
            }

            dfs(to);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int s, t;
        cin >> s >> t;

        G[s].emplace(s, t);
        G[t].emplace(s, t);
    }

    dfs(1);
    
    clearVis();
    dp[1] = init;
    dfs(1);

    int mi = *min_element(dp+1, dp+n+1);
    set<int> ans;
    for(int i = 1; i <= n; i++) {
        if(dp[i] == mi) ans.emplace(i);
    }

    cout << mi << endl;
    for(int x: ans) {
        cout << x << " ";
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
