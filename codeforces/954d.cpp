// https://codeforces.com/contest/954/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
const int maxn = 1005;
int n, m, s, t;

set<int> G[maxn];
int sdis[maxn];
int tdis[maxn];

void bfs(int st, int *dis) {
    queue<int> Q;
    dis[st] = 0;
    Q.push(st);

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(int adj: G[S]) {
            if(dis[adj] > dis[S]+1) {
                dis[adj] = dis[S]+1;
                Q.push(adj);
            }
        } 
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        sdis[i] = INT_MAX;
        tdis[i] = INT_MAX;
    }

    cin >> n >> m >> s >> t;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    bfs(s, sdis);
    bfs(t, tdis);

    int curdis = sdis[t];
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(!G[i].count(j)) {
                if(sdis[i]+tdis[j]+1 >= curdis and sdis[j]+tdis[i]+1 >= curdis) {
                    ans++;
                } 
            }
        }
    }

    cout << ans << endl;   
}