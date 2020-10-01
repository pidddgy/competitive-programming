// https://codeforces.com/problemset/problem/909/C

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

const int maxn = 5050;
const int MOD = (int)1e9+7;

int n;
char a[maxn];
int dp[2][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        int cur = i%2;
        int prev = cur^1;

        for(int j = 1; j <= 5000; j++) dp[cur][j] = 0;

        int ma = 0;
        if(a[i-1] == 's') {
            for(int j = 1; j <= 5000; j++) {
                if(dp[prev][j]) ma = j;
            }
        }

        if((a[i-1] == 's')) {
            int hugs = 0;
            for(int j = ma; j >= 1; j--) {
                hugs += dp[prev][j];
                dp[cur][j] += hugs;
                dp[cur][j] %= MOD;
            }
        }

        if(a[i-1] == 'f') {
            for(int j = 2; j <= 5000; j++) {
                dp[cur][j] += dp[prev][j-1];
                dp[cur][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 5000; i++) {
        ans += dp[n%2][i];
        ans %= MOD;
    }

    cout << ans << endl;
}

/*

dp[i][j] = number of ways to get to [line #][current indentation level]
start at indentation level 1
if a[i-1] is f
    transition from dp[i-1][j-1] because we must indent one out
if a[i-1] is s
    transition from dp[i-1][j] and dp[i-1][j+1]
    

use the flippy flop dp thing to save memory uwu

8
f
s
f
f
s
f
s
s

5
f
f
s
f
s

for
    for
        state
            for
                state

for
    for
        state
        for
            state
for
    for
        state

for
    state
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
