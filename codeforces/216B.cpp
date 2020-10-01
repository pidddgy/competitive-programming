// https://codeforces.com/contest/216/problem/B

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

const int maxn = 150;

bool adj[maxn][maxn];
bool vis[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = adj[v][u] = true;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        int t = 1, e = 0;
        queue<int> Q;
        Q.push(i);
        vis[i] = true;

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            for(int j = 1; j <= n; j++) {
                if(adj[S][j]) {
                    e++;
                    if(!vis[j]) {
                        t++;
                        vis[j] = true;
                        Q.push(j);
                    }
                }
            }
        }

        e /= 2;

        if((t == e) and (t % 2)) {
            ans++;
        }
    }

    if((n-ans)%2) {
        ans++;
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
