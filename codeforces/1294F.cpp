// https://codeforces.com/contest/1294/problem/F

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

const int maxn = 200500;

vector<int> G[maxn];
int dis[maxn], par[maxn];
bool bad[maxn];
pii best = {0, 1};

void cl() {
    for(int i = 0; i < maxn; i++) {
        dis[i] = par[i] = 0;
    }
}

void dfs(int v, int p) {
    // cerr << "On " << v << endl;
    best = max(best, pii(dis[v], v));
    for(int to: G[v]) {
        if(to == p) continue;
        if(bad[to]) continue;

        dis[to] = dis[v]+1;
        par[to] = v;

        dfs(to, v);
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(1, -1);
    int tot = 0;
    cl();

    int a = best.se;
    best = pii(0, a);
    dfs(a, -1);

    int b = best.se;
    tot += best.fi;

    int cur = b;
    int ree = 0;
    while(cur != a and cur != 0) {
        bad[cur] = true;
        cur = par[cur];
    }

    bad[cur] = true;
    cl();

    best = pii(0, a);
    cl();
    for(int i = 1; i <= n; i++) {
        if(bad[i]) {
            dfs(i, -1);
        }
    }

    tot += best.fi;
    int c = best.se;

    for(int i = 1; i <= n; i++) {
        if(a == i) continue;
        if(b == i) continue;

        if(c == a or c == b) c = i;
    }


    cout << tot << endl;
    cout << a << " " << b << " " << c << endl;
}

/*

get diameter, add best

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
