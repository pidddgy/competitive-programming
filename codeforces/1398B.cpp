// https://codeforces.com/contest/1398/problem/B

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
    string s;
    cin >> s;
    int n = sz(s);
    s = "?"+s;

    vector<int> chunks;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') {
            if(cur) {
                chunks.emplace_back(cur);
                cur = 0;
            }
        } else {
            cur++;
        }
    }

    if(cur) {
        chunks.emplace_back(cur);
        cur = 0;
    }

    sort(all(chunks), greater<int>());

    int ans = 0;
    for(int i = 0; i < chunks.size(); i += 2) {
        ans += chunks[i];
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
        solve();
    }
}

/*

count "chunks"
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
