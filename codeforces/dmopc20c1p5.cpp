// https://dmoj.ca/problem/dmopc20c1p5

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

const int maxn = 2005;


int n, l;
// vector<vector<int>> adj;
vector<int> adj[maxn];
int tin[maxn], tout[maxn];
int timer = 0;
int par[maxn];
// vector<int> tin, tout;

void dfs(int v, int p)
{
    tin[v] = ++timer;

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}


set<int> S[maxn];
int c[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;    

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        S[c[i]].emplace(i);
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    dfs(1, -1);

    watch(is_ancestor(1, 2))
    watch(tin[1])
    watch(tout[1])

    watch(tin[2])
    watch(tout[2])

    

    for(int query = 1; query <= m; query++) {
        int t;
        cin >> t;

        if(t == 1) {
            int ind, alien;
            cin >> ind >> alien;

            // cerr << "e" << endl;

            S[c[ind]].erase(ind);
            S[alien].emplace(ind);
            
            c[ind] = alien;

            // cerr << "done" << endl;
        }

        if(t == 2) {
            int u;
            cin >> u;

            int res = 0;
            for(int i = 1; i <= k; i++) {
                int cute = 0; // <3
                for(int ind: S[i]) {
                    cerr << "checking " << u << " "  << ind << endl;
                    if(is_ancestor(u, ind)) {
                        cerr << "yes" << endl;
                        cute = 1;
                    } else {
                        cerr << "no" << endl;
                    }
                }

                res += cute;
            }

            cout << res << endl;
            cerr << endl;
        }
    }
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
