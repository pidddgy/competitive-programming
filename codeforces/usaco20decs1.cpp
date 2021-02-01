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

vector<int> G[maxn];
bool vis[maxn];
int have[maxn];

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

    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    have[1] = 1;

    int ans = 0;
    while(!Q.empty()) {
        int S = Q.front(); Q.pop();

        int need = 0;
        for(int adj: G[S]) {
            if(vis[adj]) continue;

            need++;

            have[adj] = 1;
            Q.push(adj);
            ans++;
            vis[adj] = true;
        }
        need++;

        cerr << "on " << S << endl;
        watch(need)
        watch(have[S])
        cerr << endl;
        while(have[S] < need) {
            have[S] *= 2;
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
