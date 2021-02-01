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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

const int maxn = 200;

int n;
int dis[maxn][maxn];
vector<int> G[maxn];

// graph split by parity
vector<int> Gpar[maxn];

void bfs(int st) {
    queue<int> Q;
    Q.push(st);
    dis[st][st] = 0;

    while(!Q.empty()) {
        int S = Q.front(); Q.pop();
        for(int to: G[S]) {
            if(dis[st][to] > dis[st][S]+1) {
                Q.push(to);
                dis[st][to] = dis[st][S]+1;
            }
        }
    }
}

bool vis[maxn];

void solve() {
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            dis[i][j] = 1e18;
        }
        G[i].clear();
        Gpar[i].clear();
        vis[i] = false;
    } 

    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= n; i++) bfs(i);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dis[1][i]%2 == dis[1][j]%2 and dis[i][j] <= 3) {
                Gpar[i].emplace_back(j);
                Gpar[j].emplace_back(i);
            }
        }
    }

    // do all with even distance from 1
    vector<int> v;

    stack<int> Q;
    Q.push(1);
    vis[1] = true;

    while(!Q.empty()) {
        int S = Q.top(); Q.pop();
        v.emplace_back(S);
        for(int to: Gpar[S]) {
            if(!vis[to]) {
                vis[to] = true;
                Q.push(to);
            }
        }

            if(Q.empty()) {
                for(int to: G[S]) {
                if(!vis[to]) {
                    vis[to] = true;
                    Q.push(to);
                }
            }
        }
    }
    for(int x: v) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
