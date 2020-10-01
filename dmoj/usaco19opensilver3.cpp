// https://dmoj.ca/problem/usaco19opensilver3

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;
int N, M;
set<int> G[maxn];
bool vis[maxn];
pii a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    for(int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace(b);
        G[b].emplace(a);
    }

    int ans = INT_MAX;
    for(int i = 1; i <= N; i++) {
        if(vis[i]) continue;

        pii hori = {INT_MAX, INT_MIN};
        pii vert = {INT_MAX, INT_MIN};
        queue<int> Q;
        Q.push(i);
        vis[i] = true;

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            
            hori.fi = min(hori.fi, a[S].fi);
            hori.se = max(hori.se, a[S].fi);
            vert.fi = min(vert.fi, a[S].se);
            vert.se = max(vert.se, a[S].se);
            for(int adj: G[S]) {
                if(!vis[adj]) {
                    Q.push(adj);
                    vis[adj] = true;
                }
            }
        }

        watch(i)
        cerr << hori.fi << "," << hori.se << endl;
        cerr << vert.fi << "," << vert.se << endl;
        watch((hori.se-hori.fi+1)*2 + (vert.se-vert.fi+1)*2)

        ans = min(ans, (hori.se-hori.fi)*2 + (vert.se-vert.fi)*2);
        cerr << endl;
    }

    cout << ans << endl;
}
