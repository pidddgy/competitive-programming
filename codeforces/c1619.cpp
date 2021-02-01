// https://cses.fi/problemset/task/1619

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> events;
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;

        events.emplace_back(l, 1);
        events.emplace_back(r, -1);
    }

    sort(all(events));

    int ans = 0;
    int cur = 0;

    for(pii x: events) {
        cur += x.se;
        ans = max(ans, cur);
    }

    cout << ans << endl;
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
