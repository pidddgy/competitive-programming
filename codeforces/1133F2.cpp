// https://codeforces.com/contest/1133/problem/F2

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
int n, m, d;
vector<int> G[maxn];
bool vis[maxn], vis2[maxn];
vector<pii> ans;
bool initused[maxn];

void no() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    if(sz(G[1]) < d) {
        no();
    }

    queue<int> Q;

    vis2[1] = true;
    for(int adj: G[1]) {
        if(!d) break;

        queue<int> Q2;
        if(!vis2[adj]) {
            Q.push(adj);
            vis[adj] = true;
            initused[adj] = true;
            cerr << "pushing " << adj << endl;
            ans.emplace_back(1, adj);

            vis2[adj] = true;
            Q2.push(adj);

            while(!Q2.empty()) {
                int S = Q2.front(); Q2.pop();

                for(int to: G[S]) {
                    if(!vis2[to]) {
                        Q2.push(to);
                        vis2[to] = true;
                    }
                }
            }

            d--;
        }
    }

    // watch(d)
    for(int adj: G[1]) {
        if(d and !initused[adj]) {
            cerr << "pushing " << adj << endl;
            ans.emplace_back(1, adj);
            Q.push(adj);
            vis[adj] = true;
            d--;
        }
    }

    vis[1] = true;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        for(int adj: G[S]) {
            if(!vis[adj]) {
                vis[adj] = true;
                Q.push(adj);
                ans.emplace_back(S, adj);
            }
        }
    }

    if(sz(ans) != n-1) {
        no();
    }

    cout << "YES" << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

if vertex 1 has < D edges, NO

just print whatever graph xd



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
