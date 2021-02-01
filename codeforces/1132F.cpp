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

const int maxn = 505;

int n;
int dp[maxn][maxn];
string s;

void f(int l, int r) {
    if(l > r) {
        dp[l][r] = 0;
    } else if(l == r) {
        dp[l][r] = 1;
    } else {
        if(dp[l+1][r] == -1) f(l+1, r);
        dp[l][r] = 1 + dp[l+1][r];
        for(int i = l+1; i <= r; i++) {
            if(s[l] == s[i]) {
                if(dp[l+1][i-1] == -1) f(l+1, i-1);
                if(dp[i][r] == -1) f(i, r);

                cerr << "for " << l  << " " << r << " we can tranistion using " << i << " to get " << dp[l+1][i-1] + dp[i][r] << endl;
                cerr << s[l] << " " << s[i] << endl;
                dp[l][r] = min(dp[l][r], dp[l+1][i-1] + dp[i][r]);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            dp[i][j] = -1;
        }
    }
    cin >> n;

    cin >> s;

    s = "."+s;

    f(1, n);

    cout << dp[1][n] << endl;

    watch(dp[2][2])
    watch(dp[3][n])
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
