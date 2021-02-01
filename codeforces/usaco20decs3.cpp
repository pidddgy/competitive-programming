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

const int maxn = 1005;

int n;
char t[maxn];
// int r[maxn], c[maxn];
int x[maxn], y[maxn];
int ans[maxn];
bool blocked[maxn];

int car[maxn];
bool vis[maxn];

vector<int> G[maxn];

int dis(int r1, int c1, int r2, int c2) {
    return abs(r1-r2) + abs(c1-c2);
}

vector<pair<int, pii>> edges;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        ans[i] = 1e18;
        car[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;

            int a = t[i];
            int b = t[j];

            if(a == 'N' and b == 'E') {
                // if the one going up is below the one going right
                if(x[i] >= x[j] and y[i] <= y[j]) {
                    pii p = {x[i], y[j]};

                    int disi = dis(x[i], y[i], p.fi, p.se);
                    int disj = dis(x[j], y[j], p.fi, p.se);
                    
                    if(disi != disj)
                    edges.push_back({max(disi, disj), {i, j}});
                }
            }
        }
    }

    sort(all(edges));

    for(auto e: edges) {
        int i = e.se.fi;
        int j = e.se.se;

        pii p = {x[i], y[j]};

        int disi = dis(x[i], y[i], p.fi, p.se);
        int disj = dis(x[j], y[j], p.fi, p.se);

        if(disi > disj and disj <= ans[j] and disi < ans[i]) {
            cerr << j << " stops cow " << i << endl;
            ans[i] = disi;
            // merge(i, j);
            G[j].emplace_back(i);
        } else if(disj > disi and disi <= ans[i] and disj < ans[j]) {
            // ans[j] = min(ans[j], disj);
            ans[j] = disj;
            cerr << i << " stops cow " << j << endl;
            // merge(j, i);
            G[i].emplace_back(j);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) vis[j] = false;
        int out = 0;
        queue<int> Q;
        Q.push(i);
        vis[i] = true;

        while(!Q.empty()) {
            int S = Q.front(); Q.pop();
            for(int adj: G[S]) {
                if(vis[adj]) continue;
                vis[adj] = true;
                Q.push(adj);

                out++;
            }
        }

        cout << out << endl;
    }
}

/*

brute force each pair of cows

find intersection point

the one who reaches the intersection point first gets answer compared



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
