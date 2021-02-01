// https://codeforces.com/contest/1118/problem/F1

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
int a[maxn];
int n;
vector<int> G[maxn];

pii dp[maxn];

void dfs1(int node, int par) {
    if(a[node] == 1) dp[node].fi++;
    if(a[node] == 2) dp[node].se++;

    for(int to: G[node]) {
        if(to != par) {
            dfs1(to, node);
            dp[node].fi += dp[to].fi;
            dp[node].se += dp[to].se;
        }
    }    
}

int ans = 0;
void dfs2(int node, int par) {
    for(int to: G[node]) {
        if(to != par) {
            // if adjacent has all of the red/blue nodes and it doesnt have any of the other kind
            if((dp[to].fi == dp[node].fi) or (dp[to].se == dp[node].se)) {
                if(min(dp[to].fi, dp[to].se) == 0) {
                    cerr << "edge between " << node << " " << to << " is good" << endl;
                    ans++;
                }
            }

            dp[node].fi -= dp[to].fi;
            dp[node].se -= dp[to].se;
            dp[to].fi += dp[node].fi;
            dp[to].se += dp[node].se;

            dfs2(to, node);
            
            dp[to].fi -= dp[node].fi;
            dp[to].se -= dp[node].se;
            dp[node].fi += dp[to].fi;
            dp[node].se += dp[to].se;
        }
    }    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs1(1, -1);
    for(int i = 1; i <= n; i++) {
        cerr << dp[i].fi << " " << dp[i].se << endl;
    }
    dfs2(1, -1);

    cout << ans << endl;


}

/*

tree rerooting dp

pii dp[i] = number of red/blue nodes in this subtree

when transition

dp[node] -= dp[to];
dp[to] += dp[node]

reverse:

dp[to] -= dp[node]
dp[node] += dp[to]

for all adjacent edges, check if to.red = node.red or to.blue = cur.blue (do not do parent or you will overcount)

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
