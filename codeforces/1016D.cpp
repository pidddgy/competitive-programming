// https://codeforces.com/contest/1016/problem/D

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
int a[maxn], b[maxn];
int ans[maxn][maxn];

void no() {
    cout << "NO" << endl;
    exit(0);
}

void go(int bit) {
    vector<int> r(maxn), c(maxn);
    int rcnt = 0, ccnt = 0;

    for(int i = 1; i <= n; i++) {
        if(a[i] & (1LL << bit)) {
            r[i] = true;
            rcnt++;
        }
    }

    for(int i = 1; i <= m; i++) {
        if(b[i] & (1LL << bit)) {
            c[i] = true;
            ccnt++;
        }
    }

    if(rcnt%2 != ccnt % 2) {
        no();
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(r[i] and c[j]) {
                ans[i][j] |= (1LL << bit);
                r[i] = c[j] = 0;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(r[i]) {
            ans[i][1] |= (1LL << bit);
            r[i] = 0;
        }
    }

    for(int i = 1; i <= m; i++) {
        if(c[i]) {
            ans[1][i] |= (1LL << bit);
            c[i] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for(int i = 35; i >= 0; i--) {
        go(i);
    }
    for(int i = 1; i <= n; i++) {
        int xo = 0;
        for(int j = 1; j <= m; j++) {
            xo ^= ans[i][j];
        }

        assert(a[i] == xo);
    }

    for(int i = 1; i <= m; i++) {
        int xo = 0;
        for(int j = 1; j <= n; j++) {
            xo ^= ans[j][i];
        }

        assert(b[i] == xo);
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

/*



cases
2 2
2 2
2 2

answer ->
2 0
0 2

2 3
1 2
3 4 5

solve bit by bit
easier subproblem on 0/1 -> each row and column is 0 or 1 and put in only 0 and 1

r and c are arrays
pick any two indexes to toggle

count of set bits in r and c should have same parity





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
