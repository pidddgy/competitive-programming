// https://codeforces.com/problemset/problem/758/C

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

const int maxn = 105;

int row[maxn];
int a[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

    int op = m*(2*n - 2);
    if(n == 1) op = m;
    int whole;
    watch(op)
    if(op == 0) whole = 0;
    else {
        whole = k/op;
        k %= op;
    }


    row[1] = whole;
    for(int i = 2; i <= n-1; i++) {
        row[i] = 2*whole;
    }
    row[n] = whole;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m and k; j++) {
            a[i][j]++;
            k--;
        }
    }

    for(int i = n-1; i >= 2; i--) {
        for(int j = 1; j <= m and k; j++) {
            a[i][j]++;
            k--;
        }
    }

    int ma = LLONG_MIN, mi = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            mi = min(mi, a[i][j]+row[i]);
            ma = max(ma, a[i][j]+row[i]);
        }
    }

    cout << ma << " " << mi << " " << a[x][y]+row[x] << endl;
}

/*

think about operations

how many in a full operation? mod, then simulate

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
