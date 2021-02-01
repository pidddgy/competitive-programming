// https://codeforces.com/contest/366/problem/C

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
const int shift = 10002;

int n, k;
int a[maxn], b[maxn];
int dp[maxn][10*maxn*103];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] *= k;
    }

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < 5*maxn*103; j++) {
            dp[i][j] = LLONG_MIN+500;
        }
    }

    dp[0][0+shift] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = -1e4; j <= 1e4; j++) {
            if(dp[i][j+shift] != LLONG_MIN+500) {
                dp[i+1][j+shift] = max(dp[i+1][j+shift], dp[i][j+shift]);
                dp[i+1][j + a[i+1]-b[i+1] + shift] = max(dp[i+1][j + a[i+1]-b[i+1] + shift], dp[i][j+shift]+a[i+1]);
            }
        }
    }

    if(dp[n][shift] == 0) {
        cout << -1 << endl;
    } else {
        cout << dp[n][shift] << endl;
    }
}

/*

dp[i][j] = ith index, j difference, max value

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
