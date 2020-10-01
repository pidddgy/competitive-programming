// https://codeforces.com/problemset/problem/682/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;
const int INF = INT_MAX-200;

set<pii> G[maxn];
int dis[maxn];
bool vis[maxn];
bool vis2[maxn];
int a[maxn];
bool bad[maxn];

void dfs(int node, int mi) {
    cerr << "currently on " << node << endl;
    watch(dis[node])
    if(dis[node]-mi > a[node]) {
        cerr << node << " is bad" << endl;
        bad[node] = true;
        return;
    }

    for(pii adj: G[node]) {
        if(dis[adj.fi] > dis[node]+adj.se and !vis[adj.fi]) {
            cerr << "pushing " << adj.fi << endl;
            vis[adj.fi] = true;
            dis[adj.fi] = dis[node]+adj.se;
            dfs(adj.fi, min(mi, dis[adj.fi]));
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < maxn; i++) {
        dis[i] = INF;
    }

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 2; i <= n; i++) {
        int p, c;
        cin >> p >> c;

        G[i].emplace(pii(p, c));
        G[p].emplace(pii(i, c));
    }

    dis[1] = 0;
    dfs(1, 0);

    for(int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    queue<int> Q;
    Q.push(1);
    vis[1] = true;

    int ans = 0;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        ans++;
        for(pii adj: G[S]) {
            if(!bad[adj.fi] and !vis[adj.fi]) {
                Q.push(adj.fi);
                vis[adj.fi] = true;
            }
        }
    }

    cout << n-ans << endl;

}
