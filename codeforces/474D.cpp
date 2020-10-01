// https://codeforces.com/problemset/problem/474/D  

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

const int MOD = (int)1e9+7;

const int maxab = 100500;

int dp[maxab];
int psa[maxab];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t, k;
    cin >> t >> k;

    dp[0] = 1;
    for(int i = 1; i <= 1e5; i++) {
        dp[i] = dp[i-1];
        dp[i] %= MOD;

        if(i >= k) {
            dp[i] += dp[i-k];
            dp[i] %= MOD;
        }

        psa[i] = psa[i-1] + dp[i];
        psa[i] %= MOD;
    }

    while(t--) {
        int a, b;
        cin >> a >> b;

        cout << ((psa[b]-psa[a-1])+MOD)%MOD << endl;
    }
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
