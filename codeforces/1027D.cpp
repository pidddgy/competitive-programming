// https://codeforces.com/contest/1027/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define fi first
#define se second

const int maxn = 200500;

bool vis[maxn];
bool skip[maxn];

int a[maxn], c[maxn];

set<int> G[maxn];

void dfs(int n, int par) {
    skip[n] = true;
    for(int adj: G[n]) {
        if(adj == par) continue;
        if(skip[adj]) continue;

        skip[adj] = true;
        dfs(adj, n);
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        G[i].emplace(a[i]);
        G[a[i]].emplace(i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(skip[i]) {
            // cerr << "skipping " << i << endl;
            continue;
        }
        map<int, bool> traversing;
        int cur = i;
        int cost = INT_MAX;
        while(!traversing[cur]) {
            traversing[cur] = true;
            if(vis[cur]) cost = 0;
            cur = a[cur];
        }

        map<int, bool> traversing2;
        while(!traversing2[cur]) {
            traversing2[cur] = true;
            cost = min(cost, c[cur]);
            cur = a[cur];
        }

        // watch(cur)
        // watch(cost)
        ans += cost;

        for(auto x: traversing) {
            vis[x.fi] = true;
        }

        dfs(i, -1);
    }

    cout << ans << endl;
}