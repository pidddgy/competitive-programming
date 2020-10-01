// https://codeforces.com/contest/815/problem/A

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

int n, m;
int g[maxn][maxn], row[maxn], col[maxn];
int mi = LLONG_MAX;
int x, y;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> g[i][j];

            if(g[i][j] < mi) {
                mi = g[i][j];
                x = i, y = j;
            }
        }
    }

    if(n < m) {
        for(int i = 1; i <= n; i++) {
            row[i] += mi;
        }
    } else {
        for(int i = 1; i <= m; i++) {
            col[i] += mi;
        }
    }

    for(int i = 1; i <= n; i++) {
        row[i] += g[i][y] - mi;
    }

    for(int i = 1; i <= m; i++) {
        col[i] += g[x][i] - mi;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(row[i] + col[j] != g[i][j])  {
                cout << -1 << endl;
                exit(0);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) ans += row[i];
    for(int i = 1; i <= m; i++) ans += col[i];

    cout << ans << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= row[i]; j++) {
            cout << "row " << i << endl;
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= col[i]; j++) {
            cout << "col " << i << endl;
        }
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
