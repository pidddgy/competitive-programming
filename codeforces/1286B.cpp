// https://codeforces.com/contest/1286/problem/B

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

const int maxn = 2005;

int root;
vector<int> G[maxn];
int ans[maxn];
int c[maxn];

// nodes in order of smallest to biggest
vector<int> dfs(int v, int par = -1) {
    cerr << "on " << v << endl;
    vector<int> res;

    for(int to: G[v]) {
        if(to == par) continue;
        cerr << to << endl;

        vector<int> arr = dfs(to, v);

        for(int i = 0; i < sz(arr); i++) {
            if(sz(res) == c[v]) res.emplace_back(v);

            res.emplace_back(arr[i]);
        }
    }

    if(sz(res) == c[v]) res.emplace_back(v);

    if(sz(res) <= c[v]) {
        cerr << "failed on " << v << endl;
        watch(sz(res))
        cout << "NO" << endl;
        exit(0);
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int p;
        cin >> p >> c[i];

        if(p == 0) {
            root = i;
        } else {
            G[i].emplace_back(p);
            G[p].emplace_back(i);
        }
    }

    vector<int> ord = dfs(root, -1);

    cerr << "a" << endl;
    for(int i = 0; i < sz(ord); i++) {
        cerr << ord[i] << " ";
        ans[ord[i]] = i+1;
    }
    cerr << endl;

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
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
