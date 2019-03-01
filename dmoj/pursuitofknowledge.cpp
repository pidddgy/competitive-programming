// https://dmoj.ca/problem/gfssoc1j5

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<int> G[n+1];
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].emplace_back(b);
    }

    int dist[n+1][n+1];
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < n+1; j++)
            dist[i][j] = -1;
    
    for(int i = 1; i <= n; i++) {
        queue<int> Q;

        Q.push(i);
        dist[i][i] = 0;

        while(!Q.empty()) {
            int S = Q.front();
            Q.pop();

            for(auto adj: G[S]) {
                if(dist[i][adj] == -1) {
                    Q.push(adj);
                    dist[i][adj] = dist[i][S] + t;
                }
            }
        }

    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == -1) cout << "Not enough hallways!" << endl;
        else cout << dist[a][b] << endl;
    }
}
