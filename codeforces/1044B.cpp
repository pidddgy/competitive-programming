#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
// #define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

const int maxn = 1005;

int n;
vector<int> G[maxn];
// int dis[maxn];
bool vis[maxn];

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        G[i].clear();
        // dis[i] = 1e18;
        vis[i] = false;
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    int k1;
    cin >> k1;

    set<int> x;
    for(int i = 1; i <= k1; i++) {
        int x_i;
        cin >> x_i;

        x.emplace(x_i);
    }

    int k2;
    cin >> k2;

    set<int> y;
    for(int i = 1; i <= k2; i++) {
        int y_i;
        cin >> y_i;

        y.emplace(y_i);
    }

    cout << "B " << (*y.begin()) << endl;
    int R;
    cin >> R;

    int x_i;
    queue<int> Q;

    Q.push(R);
    vis[R] = true;
    while(!Q.empty()) {
        int S = Q.front();
        Q.pop();

        if(x.count(S)) {
            x_i = S;
            break;
        }

        for(int to: G[S]) {
            if(!vis[to]) {
                vis[to] = true;
                Q.push(to);
            }
        }
    }
    
    cout << "A " << x_i << endl;

    int v;
    cin >> v;

    if(y.count(v)) {
        cout << "C " << x_i << endl;
    } else {
        cout << "C " << -1 << endl;
    }

    // cout << "B"
    // int R = 
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

the closest x to any y must be a y otherwise you could cut the tree and both subtrees would be disjoint

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
