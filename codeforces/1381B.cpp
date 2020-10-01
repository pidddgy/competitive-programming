// https://codeforces.com/problemset/problem/1381/B

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

bool dp[(int)1e5];

void solve() {
    int n;
    cin >> n;

    deque<int> a;
    for(int i = 1; i <= n*2; i++) {
        int x;
        cin >> x;

        a.push_back(x);
    }

    vector<int> blocks;

    while(sz(a)) {
        int x = a.front();
        a.pop_front();

        int hugs = 1;
        while(sz(a) and a.front() < x) {
            hugs++;
            a.pop_front();
        }

        blocks.emplace_back(hugs);
    }

    for(int i = 1; i <= 4500; i++) dp[i] = false;

    dp[0] = true;
    for(int x: blocks) {
        // cerr << x << " ";
        for(int i = 2000; i >= 0; i--) {
            if(dp[i]) dp[i+x] = true;
        }
    }
    // cout << endl;

    string ans = "NO";
    if(dp[n]) ans = "YES";

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
