// https://codeforces.com/contest/449/problem/B

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

int n, m, k;
vector<pii> G[maxn];
int dis[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) dis[i] = 1e10;

    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) {
        int u, v, x;
        cin >> u >> v >> x;

        G[u].emplace_back(x, v);
        G[v].emplace_back(x, u);
    }

    priority_queue<pii> pq;
    pq.push({0, 1});
    dis[1] = 0;

    while(!pq.empty()) {
        pii p = pq.top(); pq.pop();
        if(-p.fi > dis[p.se]) continue;

        int S = p.se;
        for(pii to: G[S]) {
            if(dis[to.se] > dis[S]+to.fi) {
                dis[to.se] = dis[S]+to.fi;
                pq.push({-dis[to.se], to.se});
            }
        }
    }

    map<pii, int> cnt;
    for(int i = 1; i <= k; i++) {
        int s, y;
        cin >> s >> y;

        cnt[pii(s, y)]++;
    }

    int ans = 0;
    set<int> S;
    for(auto x: cnt) {
        pii p = x.fi;

        cerr << "on " << p.fi << " " << p.se << endl;
        watch(x.se)
        watch(dis[p.fi])

        if(dis[p.fi] <= p.se) {
            ans += x.se;
        } else {
            if(!S.count(p.fi)) {
                ans += x.se-1;
            } else {
                ans += x.se;
            }
        }

        S.emplace(p.fi);
    }

    cout << ans << endl;
}

/*



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
