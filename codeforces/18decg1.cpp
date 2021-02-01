#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)5e4+500;

// .fi = weight, .se = to
vector<pii> G[maxn];
int dis[maxn][2];
int hay[maxn];

int n, m, k;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);

    for(int i = 0; i < maxn; i++) {
        dis[i][0] = dis[i][1] = 1e18;
        hay[i] = -1e18;
    }

    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        G[u].emplace_back(w, v);
        G[v].emplace_back(w, u);
    }

    for(int i = 1; i <= k; i++) {
        int ind, y;
        cin >> ind >> y;

        hay[ind] = max(hay[ind], y);
    }

    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    dis[n][0] = 0;
    pq.push({0, {n, 0}});

    while(!pq.empty()) {
        auto S = pq.top(); pq.pop();
        pii p = S.se;
        cerr << "on " << p.fi << " " << p.se << endl;
        
        if(dis[p.fi][p.se] < S.fi) continue;
        cerr << "on " << p.fi << " " << p.se << endl;

        for(pii e: G[p.fi]) {
            cerr << p.fi << " can go to " << e.se << endl;
            // no haybale
            if(dis[e.se][p.se] > dis[p.fi][p.se]+e.fi) {
                cerr << "push w no haybale" << endl;
                watch(e.fi)
                dis[e.se][p.se] = dis[p.fi][p.se]+e.fi;
                pq.push({dis[e.se][p.se], {e.se, p.se}});
            }

            // haybale
            if(hay[e.se] != -1e18 and p.se == 0)
            if(dis[e.se][1] > dis[p.fi][p.se]+e.fi-hay[e.se]) {
                cerr << p.fi << " haybale path to " << e.se << endl;
                dis[e.se][1] = dis[p.fi][p.se]+e.fi-hay[e.se];
                pq.push({dis[e.se][1], {e.se, 1}});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << endl << dis[i][0] << " " << dis[i][1] << endl;
    }
    cerr << endl;
    for(int i = 1; i <= n-1; i++) {
        if(dis[i][1] <= dis[i][0]) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

/*

haybales are like negative weight

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
