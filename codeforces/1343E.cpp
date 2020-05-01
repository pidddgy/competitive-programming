// https://codeforces.com/contest/1343/problem/E

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

#define cerr if(false) cerr
const int maxn = 200500;
int n, m, a, b, c;
int disa[maxn];
int disb[maxn];
int disc[maxn];
vector<int> G[maxn];

void bfs(int *dis, int st) {
    queue<int> Q;

    dis[st] = 0;
    Q.push(st);

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(int adj: G[S]) {
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

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m >> a >> b >> c;

        for(int i = 1; i <= n; i++) {
            disa[i] = LLONG_MAX;
            disb[i] = LLONG_MAX;
            disc[i] = LLONG_MAX;
            G[i].clear();
        }

        int p[m+1];
        int psa[m+1];
        psa[0] = 0;
        for(int i = 1; i <= m; i++) {
            cin >> p[i];
        }

        sort(p+1, p+m+1);
        for(int i = 1; i <= m; i++) {
            psa[i] = p[i] + psa[i-1];
        }


        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;

            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        bfs(disa, a);
        bfs(disb, b);
        bfs(disc, c);

        int ans = LLONG_MAX;
        for(int i = 1; i <= n; i++) {

            int repeat = disb[i];
            int edge = disa[i]+disb[i]+disc[i];

            if(edge > m) continue;

            int cost = psa[edge] + psa[repeat];
            watch(cost)
            ans = min(ans, cost);
            cerr << endl;
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            disa[i] = LLONG_MAX;
            disb[i] = LLONG_MAX;
            disc[i] = LLONG_MAX;
            G[i].clear();
        }
    }
}