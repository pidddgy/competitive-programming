// https://codeforces.com/problemset/problem/1286/A

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

const int maxn = 150;

int a[maxn];

int dp[maxn][maxn][maxn][2];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            for(int k = 0; k < maxn; k++)
                for(int l = 0; l <= 1; l++)
                    dp[i][j][k][l] = INT_MAX; 

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int evens = n/2, odds = n-evens;

    dp[0][0][0][0] = dp[0][0][0][1] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= evens; j++) {
            for(int k = 0; k <= odds; k++) {
                // Check if already set
                if(a[i] != 0) {
                    int parity = a[i]%2;
                    // use even on last
                    if(j and parity == 0) {
                        dp[i][j][k][0] = min(dp[i-1][j-1][k][0], dp[i-1][j-1][k][1]+1);
                    }

                    if(k and parity == 1) {
                        dp[i][j][k][1] = min(dp[i-1][j][k-1][1], dp[i-1][j][k-1][0]+1);
                    }
                } else {
                    if(j) {
                        dp[i][j][k][0] = min(dp[i-1][j-1][k][0], dp[i-1][j-1][k][1]+1);
                    }

                    if(k) {
                        dp[i][j][k][1] = min(dp[i-1][j][k-1][1], dp[i-1][j][k-1][0]+1);
                    }
                }
            }
        }
    }

    cout << min(dp[n][evens][odds][0], dp[n][evens][odds][1]) << endl;
}

/*

given binary string, insert 0s and 1s that minimize complexity

0s and 1s are interchangable with evens/odds, as they represent residue mod 2

state is [index][number of 0s used][number of 1s used][last used]

if a[i] is 0
    only transition from dp[i-1][j][k]
else
    transition from dp[i-1][j-1][k], dp[i-1][j][k-1]


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
