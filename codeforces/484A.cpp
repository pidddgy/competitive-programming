// https://codeforces.com/contest/484/problem/A

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

void solve(int l, int r) {
    int ans = 9223372036854775807;

    // watch(ans & (1LL << 62));

    for(int i = 62; i >= 0; i--) {
        if(ans & (1LL << i)) {
            if(ans > r) {
                // watch(1LL << i)
                // watch(ans - (1LL << i))
                if(ans - (1LL << i) >= l) {
                    // cerr << "removing bit " << i << endl;
                    ans -= (1LL << i);
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        solve(l, r);
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