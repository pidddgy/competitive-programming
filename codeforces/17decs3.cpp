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

int a[maxn];
int vis[maxn];

vector<int> cycles;
vector<int> path;

void dfs(int v) {
    vis[v] = 1;
    path.emplace_back(v);

    if(vis[a[v]] != 2) {
        if(vis[a[v]] == 1) {
            cycles.emplace_back(0);
            while(path.back() != a[v]) {
                cycles.back()++;
                path.pop_back();
            }

            cycles.back()++;
            path.pop_back();
        } else {
            dfs(a[v]);
        }
    }

    vis[v] = 2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs(i);
    }

    int ans = 0;
    for(int x: cycles) ans += x;

    cout << ans << endl;
}

/*

functional graphs always lines that go to cycles

cycle detection

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
