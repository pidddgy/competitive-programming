// https://codeforces.com/contest/1304/problem/E

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

int n;
vector<int> G[maxn];
int tin[maxn], tout[maxn];

// 20 bits
int up[maxn][20];

int timer = 1;

void dfs(int v, int par) {
    tin[v] = timer++;

    up[v][0] = par;
    for(int i = 1; i <= 19; i++) {
        if(up[v][i-1] != -1)
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for(int to: G[v]) {
        if(to == par) continue;
        
        dfs(to, v);
    }
    tout[v] = timer++;
}

bool ancestor(int v1, int v2) {
    return (tin[v1] <= tin[v2]) and (tout[v1] >= tout[v2]);
}

int dis(int u, int v) {
    int lca = -1;
    if(ancestor(u, v)) lca = u;
    if(ancestor(v, u)) lca = v;

    int cur = u;
    for(int i = 18; i >= 0; i--) {
        if(up[cur][i] != -1 and !ancestor(up[cur][i], v)) {
            cur = up[cur][i];
        }
    }
    cur = up[cur][0];

    if(lca == -1) lca = cur;

    cerr << u << " " << v << " lca -> " << lca << endl;
    int res = 0;
    cur = u;
    for(int i = 18; i >= 0; i--) {
        if(up[cur][i] != -1 and !ancestor(up[cur][i], v)) {
            cur = up[cur][i];
            res += (1LL << i);
        }
    }
    if(cur != lca) res++;

    cur = v;
    for(int i = 18; i >= 0; i--) {
        if(up[cur][i] != -1 and !ancestor(up[cur][i], u)) {
            cur = up[cur][i];
            res += (1LL << i);
        }
    }
    if(cur != lca) res++;

    // watch(res)
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < 20; j++) {
            up[i][j] = -1;
        }
    }

    cin >> n;
    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v; 

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);

    int q;
    cin >> q;

    while(q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;

        bool ok = false;
        int len = dis(a, b);
        // watch(len)
        
        if(len%2 == k%2 and len <= k) ok = true;
        
        int cyclelen = dis(x, y)+1;
        // try going to y
        len = dis(a, x)+1+dis(y, b);
        if(len <= k and ((len%2 == k%2) or (k-len)%cyclelen == 0)) ok = true;

        len = dis(a, y)+1+dis(x, b);
        if(len <= k and ((len%2 == k%2) or (k-len)%cyclelen == 0)) ok = true;

        if(ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
}

/*

as long as we have any path <= k with same parity 
try seeing if we can get to x or y with a good parity

if we can get to x with d we can get to y with d+1
if we can get to y with d we can get to x with d+1

we can never change parity of path length



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?