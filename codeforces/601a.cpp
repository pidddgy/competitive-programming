// https://codeforces.com/contest/601/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

const int maxn = 500;
set<int> G[maxn];
set<int> inv[maxn];
int dis[maxn];

void bfs(set<int> *arr) {
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(int adj: arr[S]) {
            if(dis[adj] > dis[S]+1) {
                Q.push(adj);
                dis[adj] = dis[S]+1;
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        dis[i] = INT_MAX;
    }

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    if(G[1].count(n)) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(!G[i].count(j)) {
                    inv[i].emplace(j);
                    inv[j].emplace(i);
                }
            }
        }

        bfs(inv);
    } else {
        bfs(G);
    }

    if(dis[n] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dis[n] << endl;
    }
}