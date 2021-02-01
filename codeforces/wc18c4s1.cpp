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

const int maxn = 100500;

int disj[maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    else return disj[v] = findp(disj[v]);
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    disj[c] = d;
}

int n, m, k;
string s;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) disj[i] = i;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        if(s[u] == s[v]) merge(u, v);
    }

    int ans = 0;
    for(int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;

        if(findp(u) == findp(v)) {
            ans++;
        }
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
