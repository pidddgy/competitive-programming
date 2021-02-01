// https://codeforces.com/contest/1427/problem/C

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

int k, n;
int dp[maxn], t[maxn], r[maxn], c[maxn], ma[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> r[i] >> c[i];
    }

    int ans = 0;
    r[0] = c[0] = 1;
    for(int i = 1; i <= n; i++) {
        int best = INT_MIN;
        for(int j = i-1; j >= 0; j--) {
            if(t[i]-t[j] > 1003) {
                best = max(best, ma[j]);
                break;
            }

            int time = t[i]-t[j];
            if(abs(r[i]-r[j]) + abs(c[i]-c[j]) <= time and (dp[j] != 0 or j == 0)) {
                
                cerr << i << " can transition from " << j << endl;
                best = max(best, dp[j]);
            }
        }

        if(best != INT_MIN) {
            dp[i] = best+1;
        }

        ma[i] = max(ma[i-1], dp[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
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
