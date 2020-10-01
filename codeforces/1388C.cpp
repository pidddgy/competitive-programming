// https://codeforces.com/contest/1388/problem/C

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

int p[maxn], h[maxn];

int hap[maxn], sad[maxn];
int sum[maxn];
int n, m;

string ans = "YES";

set<int> G[maxn];
bool vis[maxn];

void dfs(int v) {
    vis[v] = true;

    cerr << "on " << v << endl;
    sum[v] = p[v];
    int ree = 0;
    for(int adj: G[v]) {
        if(!vis[adj]) {
            vis[adj] = true;
            dfs(adj);
            ree += hap[adj];
            sum[v] += sum[adj];
        }
    }

    hap[v] = (sum[v] + h[v])/2;
    sad[v] = sum[v] - hap[v];

    // if sum is odd, there is no possible solution
    if((sum[v] + h[v]) & 1) {
        cerr << "failed on" << v << endl;
        ans = "NO";
    } else if(sad[v] < 0 or hap[v] < 0) {
        ans = "NO";
    } else if(sad[v] + hap[v] > sum[v]) {
        ans = "NO";
    } else if (hap[v] - sad[v] != h[v]) {
        ans = "NO";
    } else if(hap[v] > sum[v]) {
        ans = "NO";
    } else if(sad[v] > sum[v]) {
        ans = "NO";
    } else if(hap[v] + sad[v] > m) {
        ans = "NO";
    } else if(ree > hap[v]) {
        ans = "NO";
    }
}

void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
        G[v].emplace(u);
    }

    dfs(1);

    if(!((m == hap[1] + sad[1]) and (m >= hap[1]))) {
        ans = "NO";
    }

    cout << ans << endl;

    // clear everything at end
    for(int i = 1; i <= n; i++) {
        p[i] = h[i] = hap[i] = sad[i] = sum[i] = 0;
        vis[i] = false;
        G[i].clear();
        assert(G[i].empty());
    }
    ans = "YES";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*
each child wants x happy people and y sad people
formula:
    for each child
        let sum = num of people in subtree
        let val = happiness value

        x-y = val
        x+y = sum

        2x = sum+val
        x = (sum+val)/2, y = sum-x

add all x and y, and then check if valid
    let a, b be desired happy/sad people
    valid if x+y == a+b and x >= a

remember to consider self as a child

find number of happy/sad people at start
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?