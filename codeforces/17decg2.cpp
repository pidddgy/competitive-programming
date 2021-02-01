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
const int MOD = (int)1e9+7;



int n, k;
vector<int> G[maxn];

int dp[maxn][4];
int p[maxn];

void dfs(int v, int par) {
    for(int i = 1; i <= 3; i++) {
        if(p[v] == i or p[v] == 0) {
            dp[v][i] = 1;
        }
    }

    for(int to: G[v]) {
        if(to == par) continue;

        dfs(to, v);
        for(int i = 1; i <= 3; i++) {
            int sum = 0;
            for(int j = 1; j <= 3; j++) {
                if(i != j) sum += dp[to][j];
                sum %= MOD;
            }

            dp[v][i] *= sum;
            dp[v][i] %= MOD;
        }
    }
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    cin >> n >> k;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    for(int i = 1; i <= k; i++) {
        int b, c;
        cin >> b >> c;

        p[b] = c;
    }

    dfs(1, -1);

    int ans = 0;
    for(int i = 1; i <= 3; i++) ans += dp[1][i];

    ans %= MOD;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
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
