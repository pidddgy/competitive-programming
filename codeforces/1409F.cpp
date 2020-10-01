// https://codeforces.com/contest/1409/problem/F

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

const int maxn = 205;

int n, k;
string s, t;

int dp[maxn][maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            for(int l = 0; l < maxn; l++) {
                dp[i][j][l] = INT_MIN;
            }
        }
    }

    cin >> n >> k;

    cin >> s >> t;
    s = "."+s, t = "."+t;

    if(t[1] == t[2]) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(s[i] == t[1]) cnt++;
        }

        cnt += k;

        cnt = min(cnt, n);

        int ans = 0;
        for(int i = cnt-1; i >= 0; i--) {
            ans += i;
        }

        cout << ans << endl;
        return 0;
    }

    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int l = 0; l <= k; l++) {
                if(s[i+1] == t[1]) {
                    dp[i+1][j+1][l] = max(dp[i+1][j+1][l], dp[i][j][l]);
                    dp[i+1][j][l+1] = max(dp[i+1][j][l+1], dp[i][j][l] + j);
                }
                
                if(s[i+1] == t[2]) {
                    dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l] + j);
                    dp[i+1][j+1][l+1] = max(dp[i+1][j+1][l+1], dp[i][j][l]); 
                }
                
                if(s[i+1] != t[1] and s[i+1] != t[2]) {
                    dp[i+1][j+1][l+1] = max(dp[i+1][j+1][l+1], dp[i][j][l]); 
                    dp[i+1][j][l+1] = max(dp[i+1][j][l+1], dp[i][j][l] + j);
                    dp[i+1][j][l] = max(dp[i+1][j][l], dp[i][j][l]);
                }
            }
        }
    }

    watch(dp[2][1][1])
    // watch(dp[4][2][1])
    // watch(dp[2][2][1])
    // watch(dp[1][1][1])

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            ans = max(ans, dp[n][i][j]);
        }
    }

    cout << ans << endl;
}

/*

dp[index][number of t[1]s][changes used], total subsequences
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
