// https://codeforces.com/problemset/problem/1244/D

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

const int maxn = 100500;
const int INF = LLONG_MAX/2;
int n;
int c[5][maxn], dp[5][5][maxn];
set<int> G[maxn];
int hugs[maxn];

int topo[maxn];
int curind;

void dfs(int v, int par) {
    for(int adj: G[v]) {
        if(adj != par) {
            dfs(adj, v);
        }
    }

    topo[curind--] = v;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < maxn; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    cin >> n;
    curind = n;

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }  

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    int root = -1;
    for(int i = 1; i <= n; i++) {
        // not possible
        if(G[i].size() > 2) {
            cout << -1 << endl;
            exit(0);
        }

        if(G[i].size() == 1) root = i;
    }

    assert(root != -1);
    dfs(root, -1);

    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(i != j) {
                dp[i][j][n] = c[i][topo[n]];
            }
        }
    }

    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                for(int l = 1; l <= 3; l++) {
                    if(set<int>({j, k, l}).size() < 3) continue;

                    dp[j][k][i] = min(dp[j][k][i], dp[k][l][i+1]+c[j][topo[i]]);
                }
            }
        }
    }

    int ans = INF;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            if(i == j) continue;

            ans = min(ans, dp[i][j][1]);
        }
    }

    cout << ans << endl;

    vector<int> last = {-1, -2, -3, -5};
    for(int i = 1; i <= n-1; i++) {
        int mi = LLONG_MAX;
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(set<int>({last.back(), j, k}).size() < 3) continue;
                if(set<int>({last[sz(last)-2], last.back(), j}).size() < 3) continue;

                mi = min(mi, dp[j][k][i]);
            }
        }

        bool found = false;
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(set<int>({last.back(), j, k}).size() < 3) continue;
                if(set<int>({last[sz(last)-2], last.back(), j}).size() < 3) continue;

                if(dp[j][k][i] == mi) {
                    hugs[topo[i]] = j;
                    if(i == n-1) {
                        hugs[topo[n]] = k;
                    }
                    // last = j;
                    last.emplace_back(j);
                    found = true;
                }

                if(found) break;
            }
            if(found) break;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << hugs[i] << " ";
    }
    cout << endl;
}

/*
dp indexes are in topological sort order 
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?