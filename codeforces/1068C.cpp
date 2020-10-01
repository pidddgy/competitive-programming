// https://codeforces.com/contest/1068/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

const int maxn = 105;
vector<pii> ans[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;


    for(int i = 1; i <= n; i++) {
        ans[i].emplace_back(i, i);
    }

    int cur = n+1;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        ans[u].emplace_back(cur, u);
        ans[v].emplace_back(cur, v);

        cur++;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i].size() << endl;
        for(pii x: ans[i]) {
            cout << x.fi << " " << x.se << endl;
        }
        cout << endl;
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
