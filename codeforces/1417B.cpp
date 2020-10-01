// https://codeforces.com/contest/1417/problem/B

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

const int maxn = 100500;

int a[maxn];
int ans[maxn];

void solve() {
    int n, t;
    cin >> n >> t;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int par = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i]*2 == t) {
            ans[i] = par;
            par ^= 1;
        } else if(a[i] <= t/2) {
            ans[i] = 0;
        } else {
            ans[i] = 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
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
