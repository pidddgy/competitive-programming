// https://codeforces.com/contest/404/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define ll long long
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)1e6+420;
const int MOD = (int)1e9+7;

int n;

// dp[i][l][r]
int dp[maxn][4][4];

// contradiction
void contr() {
    cout << 0 << endl;
    exit(0);
}

int madd(int a, int b) {
    ll sum = a+b;
    sum %= MOD;

    return sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    n = sz(s);
    s = "."+s;

    // if(s[1] == '2' or s[n] == '2') contr();

    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int l = 0; l <= 3; l++) {
            for(int m = 0; m <= 3; m++) {
                for(int r = 0; r <= 3; r++) {
                    if((i == 1) and !(l == 0 and m == 0)) continue;
                    if((i == 2) and !(l == 0)) continue;

                    bool ok = true;
                    if(i >= 2) {
                        // check middle
                        if(m == 0 and (l == 3 or r == 3)) {
                            ok = false;
                            continue;
                        }

                        if(m == 1 and !(l == 3 ^ r == 3)) {
                            ok = false;
                            continue;

                        }

                        if(m == 2 and (l != 3 or r != 3)) {
                            ok = false;
                            continue;

                        }
                    }

                    // check right
                    if(r == 0 and m == 3) {
                        ok = false;
                            continue;

                    }

                    if(r == 2 and m != 3) {
                        ok = false;
                            continue;

                    }

                    if(r == 1 and i == n and m != 3) {
                        ok = false;
                            continue;

                    }

                    if(r == 2 and i == n) {
                        ok = false;
                            continue;

                    }

                    vector<int> v = {r, m, l};
                    for(int j = 0; j < 3; j++) {
                        if(s[i-j] == '?') continue;
                        if(i-j < 1) continue;

                        if((v[j] == 3)) {
                            if(s[i-j] != '*') {
                                ok = false;
                            continue;

                            }
                        } else if(s[i-j]-'0' != v[j]) {
                            ok = false;
                            continue;

                        }

                    }

                    if(ok) {
                        dp[i][m][r] = madd(dp[i][m][r], dp[i-1][l][m]);
                        // dp[i][m][r] += dp[i-1][l][m];
                        // dp[i][m][r] %= MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            ans = madd(ans, dp[n][i][j]);
            // ans += dp[n][i][j];
            // ans %= MOD;
        }
    }

    cout << ans << endl;
}

/*

index i is only affected by last 2

for i in 1..n
    ans += (# s[i] == 0) + (# s[i] == 1)

dp[0][0] = 1

dp[i][mask]
    -> mask < 4

for i in 2..n
    for j in 0, 1
        for f in 0..4
            check if dp[i-2][f] can be used for j

when checking, f+j should not create contradiction
contradiction is when:
    - s[i] = 0 but s[i-1] or s[i+1]
    - s[i] = 1 but s[i-1] and s[i+1] 
    - s[i] = 2 but s[i-1] == 0 or s[i+1] = 0

check middle for all
check right for the or conditions (-1)

if s[n] == 2 print 0

256 000 000

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
