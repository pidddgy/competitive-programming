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

const int maxn = 200500;

int n;
int w[maxn];
vector<int> G[maxn];

void solve() {
    int sum = 0;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        w[i] = 0;
        G[i].clear();
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        ans += w[i];
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    
    vector<int> pq;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sz(G[i])-1; j++) {
            pq.emplace_back(w[i]);
        }
    }

    sort(all(pq), greater<int>());

    // watch(sz(pq))
    cout << ans << " ";
    for(int x: pq) {
        ans += x;
        cout << ans << " ";
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

heaviest non leaf

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
