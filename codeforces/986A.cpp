// https://codeforces.com/contest/986/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
const int maxn = 100500;
const int maxk = 105;
const int INF = INT_MAX-100;
set<int> G[maxn];
int dis[maxk][maxn];
int type[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxk; i++) {
        for(int j = 0; j < maxn; j++) {
            dis[i][j] = INF;
        }
    }

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    for(int i = 1; i <= n; i++) {
        cin >> type[i];
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    for(int t = 1; t <= k; t++) {
        queue<int> Q;
        for(int i = 1; i <= n; i++) {
            if(type[i] == t) {
                Q.push(i);
                dis[t][i] = 0;
            }
        }

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            for(int adj: G[S]) {
                if(dis[t][adj] > dis[t][S]+1) {
                    Q.push(adj);
                    dis[t][adj] = dis[t][S]+1;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        vector<int> costs;
        for(int j = 1; j <= k; j++) {
            costs.emplace_back(dis[j][i]);
        }
        sort(costs.begin(), costs.end());

        int ans = 0;
        for(int j = 0; j < s; j++) {
            ans += costs[j];
        }

        cout << ans << " ";
    }
    cout << endl;
}