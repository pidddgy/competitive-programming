// https://codeforces.com/contest/1276/problem/B

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

const int maxn = 200500;

int n, m, a, b;
vector<int> G[maxn];
bool visa[maxn], visb[maxn];

void dfs(int v, bool var[]) {
    var[v] = true;

    for(int adj: G[v]) {
        if(!var[adj]) {
            var[adj] = true;
            dfs(adj, var);
        }
    }
}

void solve() {
    cin >> n >> m >> a >> b;
    // clear everything    
    for(int i = 1; i <= n; i++) {
        G[i].clear();
        visa[i] = visb[i] = false;
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    visa[b] = true;
    dfs(a, visa);

    visb[a] = true;
    dfs(b, visb);

    int c1 = 0, c2 = 0;
    for(int i = 1; i <= n; i++) {
        if(visa[i] and !visb[i]) {
            c1++;
        }

        if(visb[i] and !visa[i]) {
            c2++;
        }
    }

    cout << c1*c2 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }    
}

/*

run dfs from a, b

if visisted by only a, forced to go through a
if visited by only b, forced to go through b

if visited by both a and b
    can visit each other without going through either

construct cases with cut edges



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
