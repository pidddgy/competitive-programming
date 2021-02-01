// https://codeforces.com/contest/1102/problem/F

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

const int maxn = 17;
const int maxm = (int)1e4+50;

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

int n, m;
int a[maxn][maxm];
int adj[maxn][maxn];

int cntbits(int num) {
    int res = 0;
    for(int i = 0; i < 20; i++) {
        if(num & (1LL << i)) res++;
    }

    return res;
}
// wrap aorund edge
int adj2[maxn][maxn];

// [end][mask]
int dis[maxn][(1LL) << maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            adj[i][j] = adj[j][i] = adj2[i][j] = adj2[j][i] = LLONG_MAX;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= m; k++) {
                adj[i][j] = adj[j][i] = min({adj[i][j], adj[j][i], abs(a[i][k] - a[j][k])});
            }

            // go from i -> j
            for(int k = 1; k <= m-1; k++) {
                adj2[i][j] = min({adj2[i][j], abs(a[i][k] - a[j][k+1])});
            }
        }
    }
    
    int ans = -5;

    // dijkstra but we want max distance

    // i as first row
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < maxn; j++) {
            for(int k = 0; k < ((1LL) << maxn); k++) {
                dis[j][k] = LLONG_MIN;
            }
        }

        // .fi = distance, .se = mask
        priority_queue<pair<int, pii>> pq;
        dis[i][1 << (i-1)] = LLONG_MAX;

        int loc = LLONG_MAX;
        pq.push({LLONG_MAX, pii(i, 1LL << (i-1))});

        while(!pq.empty()) {
            auto S = pq.top(); pq.pop();

            int v = S.se.fi;
            int mask = S.se.se;
            int d = dis[v][mask];

            if(cntbits(mask) == n) {
                int ree = d;
                if(m > 1) ree = min(ree, adj2[v][i]);
                ans = max(ans, ree);
            }

            for(int k = 1; k <= n; k++) {
                if(!(mask & (1LL << (k-1)))) {
                    int nm = mask|(1LL << (k-1));
                    int nd = min(d, adj[v][k]);

                    if(nd > dis[k][nm]) {
                        dis[k][nm] = nd;
                        pq.push({nd, pii(k, nm)});
                    }
                }
            }
        }
    }

    cout << ans << endl;
}

/*
do dijkstra on [cur][mask]

if mask has visited n-1 bits check
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?