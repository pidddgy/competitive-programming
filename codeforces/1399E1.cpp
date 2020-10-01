// https://codeforces.com/contest/1399/problem/E1

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

const int maxn = 100500;

vector<int> G[maxn];
int dis[maxn];
int dp[maxn];
int u[maxn], v[maxn], w[maxn];

int curTime = 0;

void dfs(int n) {
    if(dp[n] != -1) return;

    bool leaf = true;
    int sum = 0;
    for(int adj: G[n]) {
        if(dis[adj] > dis[n]+1) {
            leaf = false;
            dis[adj] = dis[n]+1;
            dfs(adj);
            sum += dp[adj];
        }
    }

    if(leaf) {
        dp[n] = 1;
    } else {
        dp[n] = sum;
    }
}

struct Compare {
    bool operator()(pii l, pii r) {
        int hugs = (l.fi*l.se) - ((l.fi/2)*l.se);
        int hugs2 = (r.fi*r.se) - ((r.fi/2)*r.se);
        return hugs > hugs2;
    }
};

void solve() {
    int n, S;
    cin >> n >> S;

    for(int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
        dp[i] = -1;
    }

    for(int i = 1; i <= n-1; i++) {
        cin >> u[i] >> v[i] >> w[i];

        G[u[i]].emplace_back(v[i]);
        G[v[i]].emplace_back(u[i]);
    }

    dis[1] = 0;
    dfs(1);

    multiset<pii, Compare> edges;
    int sum = 0;
    for(int i = 1; i <= n-1; i++) {
        int ma = '?';
        if(dis[u[i]] > dis[v[i]]) {
            ma = u[i];
        } else {
            ma = v[i];
        }

        edges.emplace(pii(w[i], dp[ma]));
        sum += w[i]*dp[ma];
    }

    int ans = 0;

    while(sum > S) {
        pii hugs = *edges.begin();
        assert(edges.size() == n-1);
        edges.erase(edges.lower_bound(hugs));
        cerr << "reducing " << hugs.fi << " " << hugs.se << endl;
        sum -= hugs.fi*hugs.se;
        hugs.fi /= 2;
        sum += hugs.fi*hugs.se;

        edges.emplace(hugs);

        ans++;
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i++) {
        u[i] = v[i] = w[i] = dp[i] = 0;
        dis[i] = INT_MAX;
        curTime = 0;
        G[i].clear();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

dfs for depth on unweighted (store visited time)

each edge contributes w[i]*num of leaves in subtree to total
    -> use lower when taking number of leaves in subtree

have set pii, sort by a[i].fi * a[i].se in non increasing order
    -> pop out first element, modify, emplace
    -> keep track of current sum
    -> break when sum <= S

time complexity: O(n * log(w) * log(n))
    -> dfs, each edge gets reduced at most 20 times
    -> inserting edge into set costs log(n) time
    -> 40 000 000

max sum at any point
    -> 1e5 * 1e6 * 1e5

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
