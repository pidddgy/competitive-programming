// https://codeforces.com/problemset/problem/721/C

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

const int MAXN = 5050;
const int INF = (LLONG_MAX/2)-200;
int n, m, T;

vector<pii> G[MAXN];

// min time needed to visit i nodes ending at j
// int dp[MAXN][MAXN];
int dp[2][MAXN];
int par[MAXN][MAXN];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < MAXN; i++) {
        dp[0][i] = dp[1][i] = INF;
        for(int j = 0; j < MAXN; j++) {
            // par[i][j] = pii(-1, -1);
            par[i][j] = -1;
        }
    }

    cin >> n >> m >> T;

    for(int i = 1; i <= m; i++) {
        int u, v, t;
        cin >> u >> v >> t;

        G[u].emplace_back(v, t);
    }

    dp[1][1] = 0;
    pii cur = {-1, -1};

    for(int i = 1; i <= n-1; i++) {
        int ind = i&1;
        int next = ind^1;
        cerr << "Currently on " << i << endl;
        for(int j = 1; j <= n; j++) {
            dp[next][j] = INF;
        }

        for(int j = 1; j <= n; j++) {
            for(pii e: G[j]) {
                if(dp[ind][j]+e.se < dp[next][e.fi]) {
                    dp[next][e.fi] = dp[ind][j]+e.se;
                    // par[i+1][e.fi] = pii(i, j);
                    par[i+1][e.fi] = j;
                    cerr << "pushing to " << e.fi << " with " << dp[ind][j]+e.se << endl;
                }
            }
        }
        if((dp[ind][n] <= T)) {
            cur = pii(i, n);
        }

        if((dp[next][n] <= T)) {
            cerr << "setting cur to " << i+1 << endl;
            cur = pii(i+1, n);
        }

        cerr << endl;
    }

    vector<int> ans;
    cerr << cur.fi << "," << cur.se << endl;

    while(par[cur.fi][cur.se] != -1) {
        ans.emplace_back(cur.se);
        cur.se = par[cur.fi][cur.se];
        cur.fi--;
        cerr << "cur is now " << cur.fi << " " << cur.se << endl;
    }
    ans.emplace_back(cur.se);
    reverse(all(ans));
    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dp[i][j] == INF) cerr << "I ";
            else cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
}

/*

realize that its bascially a tree (dag and you cant go backwards)

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
