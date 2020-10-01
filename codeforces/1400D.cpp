// https://codeforces.com/contest/1400/problem/D

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

const int maxn = 3005;

int a[maxn];
int psa[maxn][maxn];
// i, j = top left, ii, jj = bottom right
int query(int i, int j, int ii, int jj) {
    return psa[ii][jj] - psa[ii][j-1] - psa[i-1][jj] + psa[i-1][j-1];
}

void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i] == a[j]) {
                cerr << "1 ";
                psa[i][j]++;
            } else cerr << "0 ";
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
        cerr << endl;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i+2; j <= n; j++) {
            if(a[i] != a[j]) continue;
            cerr << "for " << i << " " << j << " there are " << query(i+1, j+1, j-1, n) << endl;
            cerr << "querying " << i+1 << "," << j+1 << " " << j-1 << "," << n << endl;
            // ans += query(i+1, j-1, j+1, n);
            ans += query(i+1, j+1, j-1, n);
        }
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i++) {
        a[i] = 0;
        for(int j = 1; j <= n; j++) {
            psa[i][j] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
