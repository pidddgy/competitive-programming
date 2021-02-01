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


const int maxn = 300500;

int k[maxn], c[maxn];
void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> c[i];
    }

    int cur = 1;

    int ans = 0;
    sort(k+1, k+n+1, greater<int>());
    for(int i = 1; i <= n; i++) {
        if(cur > k[i]) {
            ans += c[k[i]];
        } else {
            ans += c[cur];
            cur++;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

we want to use the smallest presents possible

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
