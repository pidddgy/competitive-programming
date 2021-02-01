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

const int maxn = 100500;

int n, k;
vector<int> G[maxn];
int dis[maxn];
int par[maxn];

void no() {
    cout << "No" << endl;
    exit(0);
}

void cl() {
    for(int i = 0; i < maxn; i++) dis[i] = 1e18;
}

void dfs(int v, int p) {
    int ch = 0;
    int leaves = 0 ;
    for(int to: G[v]) {
        if(to == p) continue;

        ch++;
        if(sz(G[to]) == 1) leaves++;
        dfs(to, v);
    }

    if(ch == 0) return;
    else if(ch < 3) no();
    else if(leaves != ch and leaves != 0) {
        cerr << "failed on " << v << endl;
        no();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    cl();
    queue<int> Q;
    Q.push(1);
    dis[1] = 0;
    pii cur = {-1e18, -1};
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        cur = max(cur, pii(dis[S], S));
        for(int to: G[S]) {
            if(dis[to] > dis[S]+1) {
                dis[to] = dis[S]+1;
                Q.push(to);
            }
        }
    }

    int e = cur.se;
    cerr << "furhtest away from 1 is " << e << endl;

    cl();
    dis[e] = 0;
    
    Q.push(e);
    cur = {-1e18, -1};
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        cur = max(cur, pii(dis[S], S));
        for(int to: G[S]) {
            if(dis[to] > dis[S]+1) {
                par[to] = S;
                dis[to] = dis[S]+1;
                Q.push(to);
            }
        }
    }


    vector<int> path;
    int c = cur.se;
    cerr << "furthest away from " << e << " is " << c << endl;

    while(c != e) {
        path.emplace_back(c);
        c = par[c];
    }
    path.emplace_back(e);

    for(int x: path) {
        cerr << x << " ";
    }
    cerr << endl;

    if(sz(path) != 2*k+1) no();
    int mid = path[sz(path)/2];
    
    dfs(mid, -1);

    cout << "Yes" << endl;

}

/*

take any leaf
if we go up k times we should be at the center

dfs from center with parent -1

for each node
    count children
    make sure degree >= 3
    dfs children

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
