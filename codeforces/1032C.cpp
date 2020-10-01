// https://codeforces.com/problemset/problem/1032/C

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

const int maxn = 100500;

int a[maxn];
bool dp[maxn][7];
pii par[maxn][7];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= 5; i++) {
        dp[1][i] = true;
    }

    for(int i = 2; i <= n; i++) {
        if(a[i-1] < a[i]) {
            for(int j = 1; j <= 5; j++) {
                for(int k = 1; k <= j-1; k++) {
                    if(dp[i-1][k]) {
                        dp[i][j] = true;
                        par[i][j] = pii(i-1, k);
                    }
                }
            }
        } else if(a[i-1] > a[i]) {
            for(int j = 1; j <= 5; j++) {
                for(int k = j+1; k <= 5; k++) {
                    if(dp[i-1][k]) {
                        dp[i][j] = true;
                        par[i][j] = pii(i-1, k);
                    }
                }
            }
        } else if(a[i-1] == a[i]) {
            for(int j = 1; j <= 5; j++) { 
                for(int k = 1; k <= 5; k++) {
                    if(j == k) continue;

                    if(dp[i-1][k]) {
                        dp[i][j] = true;
                        par[i][j] = pii(i-1, k);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= 5; i++) {
        if(dp[n][i]) {
            vector<int> ans;
            pii cur = pii(n, i);
            for(int j = 1; j <= n; j++) {
                // cout << cur.se << " ";
                ans.emplace_back(cur.se);
                cur = par[cur.fi][cur.se];
            }

            // cout << endl;

            reverse(ans.begin(), ans.end());
            for(int x: ans) {
                cout << x << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
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
