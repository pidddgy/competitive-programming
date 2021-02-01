// https://codeforces.com/contest/1451/problem/B

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
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    s = "."+s;

    while(q--) {
        int l, r;
        cin >> l >> r;

        // string sub = s.substr(l, r-l+1);
        // watch(sub);

        // reverse(all(sub));

        string ans = "NO";
        for(int i = l-1; i >= 1; i--) {
            if(s[i] == s[l]) {
                ans = "YES";
            }
        }

        for(int i = r+1; i <= n; i++) {
            if(s[i] == s[r]) ans = "YES";
        }

        cout << ans << endl;
    }
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
