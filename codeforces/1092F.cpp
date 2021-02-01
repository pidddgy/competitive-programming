// https://codeforces.com/contest/1092/problem/F

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

int n;
int a[maxn];
int sum[maxn];

vector<int> G[maxn];
int dis[maxn];

void dfs1(int v, int par = -1) {
    sum[v] += a[v];
    for(int to: G[v]) {
        if(to == par) continue;
        dis[to] = dis[v]+1;
        dfs1(to, v);
        sum[v] += sum[to];
    }
} 

int cur = 0;
int ans = 0;
int tot = 0;
void dfs2(int v, int par = -1) {
    cerr << v << " -> " << cur << endl;
    ans = max(ans, cur);

    for(int to: G[v]) {
        if(to != par) {
            cur += tot-sum[to];
            cur -= sum[to];

            sum[v] -= sum[to];
            sum[to] += sum[v];

            dfs2(to, v);

            sum[to] -= sum[v];
            sum[v] += sum[to];

            cur += sum[to];
            cur -= tot-sum[to];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tot += a[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    dfs1(1);
    for(int i = 1; i <= n; i++) {
        cur += dis[i]*a[i];
    }

    dfs2(1);

    cout << ans << endl;
}

/*

tree rerooting dp

maintain subtree sums and cur

dfs

update max answer

when moving from v -> to:
    cur += everything but sum[to]
    cur -= sum[to]

    sum[v] -= sum[to]
    sum[to] += sum[v]

    dfs

    reverse all operations




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
