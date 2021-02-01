// https://codeforces.com/contest/1457/problem/A

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

int trng(int n) {
    return (n*(n+1))/2;
}
int n, m, r, c;

int go(int x, int y) {
    return abs(x-r) + abs(y-c);
}
void solve() {
    cin >> n >> m >> r >> c;

    int ans = 0;

    ans = max(ans, go(1, 1));
    ans = max(ans, go(1, m));
    ans = max(ans, go(n, 1));
    ans = max(ans, go(n, m));
    cout << ans << endl;
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
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
