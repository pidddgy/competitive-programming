// https://codeforces.com/problemset/problem/983/B

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

const int maxn = 5050;

int n;
int a[maxn];
int dp[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
    }  

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            dp[i][j] = dp[i][j-1]^dp[i+1][j];
        }
    }

    for(int len = 2; len <= n; len++) {
        for(int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            dp[i][j] = max({dp[i][j], dp[i][j-1], dp[i+1][j]});
        }
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        cout << dp[l][r] << endl;
    }




}

/*


b1, b2, b3, b4

{b1, b2}, {b2, b3}, {b3, b4}
{b1, b2, b2, b3}, {b2, b3, b3, b4}
{b1, b2, b2, b3, b2, b3, b3, b4}
{b1, b2, b3, b4}
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
