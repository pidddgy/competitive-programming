// https://codeforces.com/problemset/problem/225/C  

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

const int maxn = 1005;

int n, m, x, y;

int dp[maxn][2];
// min cost if we use white/black on this one
int mic[maxn][2];

// number of black/white squares in this column
// i know wht is just n-blk but whatever
int blk[maxn], wht[maxn];
int psa[2][maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j <= 1; j++) {
            dp[i][j] = INT_MAX;
        }
    }

    cin >> n >> m >> x >> y;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= m; j++) {
            if(s[j-1] == '#') psa[1][j]++;
            else psa[0][j]++;
        }
    }

    for(int i = 0; i <= 1; i++) {
        for(int j = 1; j <= m; j++) {
            psa[i][j] += psa[i][j-1];
        }
    }

    dp[0][0] = 0;
    for(int i = 0; i <= y; i++) {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= 1; j++) {
            for(int k = x; k <= y; k++) {
                if(i-k >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i-k][j^1] + psa[j][i] - psa[j][i-k]);
                }
            }
        }
    }

    cout << min(dp[m][0], dp[m][1]) << endl;
}

/*

dp[i][j] = on column i, j previous are black
j = 0 means this column is not black

##.#.
.###.
###..
#...#
.##.#
###..

.##..
.##..
.##..
.##..
.##..
.##..

column 1 cost is 4
column 2 cost is 1
column 3 cost is 2
column 4 cost is 2
column 5 cost is 2
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
