// https://codeforces.com/problemset/problem/574/B

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int con[5000][5000];
int deg[5000];
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    int n, m;
    cin >> n >> m;

    vector<pii> edges;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        con[a][b] = true;
        con[b][a] = true;
        deg[a]++;
        deg[b]++;

        edges.emplace_back(a, b);
    }

    int ans = INT_MAX;
    for(pii e: edges) {
        int x = e.fi;
        int y = e.se;

        for(int z = 1; z <= n; z++) {
            if(z == x or z == y) continue;

            if(con[x][y] and con[y][z] and con[z][x]) {
                ans = min(ans, deg[x] + deg[y] + deg[z] - 6);
            }
        }
    }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}