// https://codeforces.com/contest/1076/problem/D

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

const int maxn = 300500;

struct Edge {
    int to, cost, ind;

    Edge(int too, int costt, int indd) {
        to = too;
        cost = costt;
        ind = indd;
    }
};

struct Compare {
    bool operator()(Edge &l, Edge &r) {
        return l.cost < r.cost; 
    }
};

vector<Edge> G[maxn];
int dis[maxn];
int last[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 3e5; i++) {
        dis[i] = 1e18;
        last[i] = -1;
    }

    int n, m, k;
    cin >> n >> m >> k;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 1; i <= m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;

        G[u].emplace_back(v, cost, i);
        G[v].emplace_back(u, cost, i);
    }    

    pq.emplace(0, 1);
    dis[1] = 0;

    int used = 0;
    vector<int> ans;
    while(sz(pq) and used < k) {
        pii S = pq.top(); pq.pop();
        cerr << "on " << S.se << endl;

        if(dis[S.se] != S.fi) continue;

        if(last[S.se] != -1) {
            ans.emplace_back(last[S.se]);
            used++;
        }

        for(Edge e: G[S.se]) {
            if(dis[e.to] > (dis[S.se] + e.cost)) {
                cerr << "pushing to " << e.to << endl;
                dis[e.to] = (dis[S.se] + e.cost);
                pq.emplace(dis[e.to], e.to);
                last[e.to] = e.ind;
            }
        }
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
