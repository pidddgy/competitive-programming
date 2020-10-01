// https://codeforces.com/contest/132/problem/C

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

int len, n;

// SHIFT represents 0
const int SHIFT = 105;

bool dp[105][2][300][60];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    len = sz(s);
    s = "."+s;

    cin >> n;

    dp[1][0][SHIFT][0] = dp[1][1][SHIFT][0] = true;

    for(int i = 1; i <= len; i++) {
        for(int j = 0; j <= 1; j++) {
            for(int k = 0; k < 203; k++) {
                for(int l = 0; l <= n; l++) {
                    if(!dp[i][j][k][l]) continue;

                    cerr << "on " << i << " " << j << " " << k << " " << l << endl;
                    // dont switch
                    if(s[i] == 'F') {
                        if(j == 0) {
                            cerr << "pushing to " << i+1 << " " << j << " " << k-1 << " " << l << endl;
                            dp[i+1][j][k-1][l] = true;
                        } else {
                            cerr << "pushing to " << i+1 << " " << j << " " << k+1 << " " << l << endl;
                            dp[i+1][j][k+1][l] = true;
                        }
                    } else {
                        cerr << "pushing to " << i+1 << " " << (j^1) << " " << k+1 << " " << l << endl;
                        dp[i+1][j^1][k][l] = true;
                    }

                    // switch
                    if(s[i] == 'T') {
                        if(j == 0) dp[i+1][j][k-1][l+1] = true;
                        else dp[i+1][j][k+1][l+1] = true;
                    } else {
                        dp[i+1][j^1][k][l+1] = true;
                    }
                }
            }
        }
    }

    int ans = INT_MIN;

    for(int i = 0; i < 203; i++) {
        for(int j = n; j >= 0; j -= 2) {
            if(dp[len+1][0][i][j] or dp[len+1][1][i][j]) {
                cerr << i << " " << j << " is valid" << endl;
                ans = max(ans, abs(SHIFT-i));
            }
        }
    }

    cout << ans << endl;
}

/*

dp[current command][direction][position][switches used]

at the beginning rather than after command is already executed
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
