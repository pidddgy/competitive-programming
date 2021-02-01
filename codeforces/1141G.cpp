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

int n, k;

vector<pii> G[maxn];
int deg[maxn];
int ans[maxn];
int r = 1;

// c = colour coming in
void dfs(int v, int par, int c) {
    cerr << "currently on " << v << " " << par << " " << c << endl;
    int cur = 0;
    for(pii e: G[v]) {
        if(e.fi == par) continue;

        if(cur == c) {
            cur++;
            cur %= r;

            // if this node has too many then use whatever colours
            c = -1;
        }

        ans[e.se] = cur;
        dfs(e.fi, v, cur);

        cur++;
        cur %= r;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n-1; i++) {
        int x, y;
        cin >> x >> y;

        G[x].emplace_back(y, i);
        G[y].emplace_back(x, i);
        deg[x]++;
        deg[y]++;
    }

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        cnt[deg[i]]++;
    }

    int over = n;   
    for(pii x: cnt) {
        if(over > k) {
            over -= x.se;
            r = x.fi;
        }
    }

    dfs(1, -1, -1);

    cout << r << endl;
    for(int i = 1; i <= n-1; i++) {
        cout << ans[i]+1 << " ";
    }
    cout << endl;


}

/*
https://codeforces.com/contest/1141/problem/G
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
