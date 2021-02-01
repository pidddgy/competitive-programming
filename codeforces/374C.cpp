// https://codeforces.com/contest/374/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

const int maxn = (int)1e3+5;

int n, m;
char a[maxn][maxn];
int cur = 1;
int node[maxn][maxn];

bool ins(int r, int c) {
    if(1 <= r and r <= n) {
        if(1 <= c and c <= m) {
            return true;
        }
    }

    return false;
}

vector<int> G[maxn*maxn];
int vis[maxn*maxn];
int dp[maxn*maxn];

int ma = 1;

void dfs(int v) {
    vis[v] = 1;
    dp[v] = 1;

    for(int to: G[v]) {
        if(vis[to] != 2) {
            if(vis[to] == 1) {
                cout << "Poor Inna!" << endl;
                exit(0);
            }

            dfs(to);
        }

        dp[v] = max(dp[v], dp[to]+1);
        ma = max(ma, dp[v]);
    }

    vis[v] = 2;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            a[i][j] = s[j-1];
            node[i][j] = -1;
        }
    }

    bool hugs = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != 'D') continue;
            for(pii x: dir) {
                if(a[i+x.fi][j+x.se] != 'I') continue;;
                for(pii y: dir) {
                    if(a[i+x.fi+y.fi][j+x.se+y.se] != 'M') continue;;
                    for(pii z: dir) {
                        if(a[i+x.fi+y.fi+z.fi][j+x.se+y.se+z.se] != 'A') continue;;

                        bool ok = true;
                        if(a[i][j] != 'D') ok = false;
                        vector<pii> v = {x, y, z};

                        string cmp = "IMA";

                        int curi = i;
                        int curj = j;
                        for(int k = 0; k < 3; k++) {
                            curi += v[k].fi;
                            curj += v[k].se;

                            if(!ins(curi, curj)) {
                                ok = false;
                                break;
                            }

                            if(a[curi][curj] != cmp[k]) ok = false;
                        }

                        // have to all be unique anyway
                        if(ok) {
                            node[i][j] = cur++;
                            hugs = true;
                        }
                        if(node[i][j] != -1) break;
                    }
                    if(node[i][j] != -1) break;
                }
                if(node[i][j] != -1) break;
            }
        }
    }

    if(!hugs) {
        cout << "Poor Dima!" << endl;
        exit(0);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cerr << node[i][j] << " ";
        }
        cerr << endl;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != 'D') continue;
            for(pii x: dir) {
                if(a[i+x.fi][j+x.se] != 'I') continue;;
                for(pii y: dir) {
                    if(a[i+x.fi+y.fi][j+x.se+y.se] != 'M') continue;;
                    for(pii z: dir) {
                        if(a[i+x.fi+y.fi+z.fi][j+x.se+y.se+z.se] != 'A') continue;;
                        bool ok = true;
                        if(a[i][j] != 'D') ok = false;
                        vector<pii> v = {x, y, z};
 
                        string cmp = "IMA";

                        int curi = i;
                        int curj = j;
                        for(int k = 0; k < 3; k++) {
                            curi += v[k].fi;
                            curj += v[k].se;

                            if(!ins(curi, curj)) {
                                ok = false;
                                break;
                            }

                            if(a[curi][curj] != cmp[k]) ok = false;
                        }

                        // have to all be unique anyway
                        if(ok) {
                            for(pii f: dir) {
                                if(ins(curi+f.fi, curj+f.se) and node[curi+f.fi][curj+f.se] != -1
                                ) {
                                    G[node[i][j]].emplace_back(node[curi+f.fi][curj+f.se]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= cur-1; i++) {
        if(!vis[i]) dfs(i);
    }

    cout << ma << endl;
}

/*

turn into graph (directed)

check for cycle

if no cycle then do dp

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
