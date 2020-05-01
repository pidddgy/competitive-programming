// https://codeforces.com/contest/659/problem/E 

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

set<int> G[maxn];
bool vis[maxn];

int bfs(int st) {
    int nEdges = 0;
    int nNodes = 0;
    queue<int> Q;

    Q.push(st);
    vis[st] = true;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        nEdges += G[S].size();
        nNodes++;
        for(int adj: G[S]) {
            if(!vis[adj]) {
                Q.push(adj);
                vis[adj] = true;
            }
        }
    }

    nEdges /= 2;

    return nEdges == nNodes-1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        G[x].emplace(y);
        G[y].emplace(x);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            ans += bfs(i);
        }
    }

    cout << ans << endl;
}