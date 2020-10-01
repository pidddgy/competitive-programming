// https://codeforces.com/problemset/problem/295/B

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

const int maxn = 505;

int dp[maxn][maxn];
int x[maxn];
bool added[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> dp[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for(int l = n; l >= 1; l--) {
        added[x[l]] = true;

        int k = x[l];
        int sum = 0;

        // try to reduce i->j by using k
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(dp[i][k]+dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k]+dp[k][j];
                }

                if(added[i] and added[j]) {
                    sum += dp[i][j];
                }
            }
        }

        ans[l] = sum;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
