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

int n, m;
vector<pair<char, int>> G[maxn];

int vis[maxn];
int c[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    cin >> n >> m;

    vector<pii> sedges, dedges;
    for(int i = 1; i <= m; i++) {
        char t;
        int u, v;
        cin >> t >> u >> v;

        G[u].emplace_back(t, v);
        G[v].emplace_back(t, u);
    }

    bool f = false;

    int cmp = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;

        c[i] = 0;
        queue<int> Q;
        Q.push(i);
        vis[i] = true;
        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            for(pii e: G[S]) {
                if(!vis[e.se]) {
                    Q.push(e.se);
                    vis[e.se] = true;

                    if(e.fi == 'D') c[e.se] = c[S]^1;
                    else c[e.se] = c[S];
                } else {
                    if(e.fi == 'D' and c[e.se] == c[S]) f = true;
                    else if(e.fi == 'S' and c[e.se] != c[S]) f = true;
                }
            }
        }

        cmp++;
    }

    if(f) {
        cout << 0 << endl;
        return 0;
    } 

    // 2 ** number of component
    cout << 1;
    for(int i = 1; i <= cmp; i++) cout << 0;

    cout << endl;
}

/*

clumps of all S edges
if no D edges connect the same clump we are fine
count connected components and multiply by 2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
