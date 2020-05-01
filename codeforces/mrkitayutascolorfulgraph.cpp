// https://codeforces.com/contest/505/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    // i = node, j = color
    vector<int> G[200][200];
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        G[a][c].emplace_back(b);
        G[b][c].emplace_back(a);
    }

    int q;
    cin >> q;

    for(int Q = 1; Q <= q; Q++) {
        int u, v;
        cin >> u >> v;

        int ans = 0;
        for(int c = 1; c <= 100; c++) {
            queue<int> Q;
            bool vis[n+1];
            for(int i = 1; i <= n; i++) {
                vis[i] = false;
            }

            vis[u] = true;
            Q.push(u);

            while(!Q.empty()) {
                int S = Q.front(); Q.pop();
                // cerr << "currently on " << S << endl;
                if(S == v) {
                    ans++;
                    break;
                }

                for(int adj: G[S][c]) {
                    if(!vis[adj]) {
                        Q.push(adj);
                        vis[adj] = true;
                    }
                }
            }
        }

        cout << ans << endl;
    }
}