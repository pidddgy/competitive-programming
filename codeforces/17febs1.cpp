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

    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);

    int c, n;
    cin >> c >> n;

    multiset<int> S;
    for(int i = 1; i <= c; i++) {
        int x;
        cin >> x;

        S.emplace(x);
    }

    int ans = 0;
    
    vector<pii> v;
    for(int i = 1; i <= n; i++) {
        int x, y; 
        cin >> x >> y;

        v.emplace_back(x, y);
    }

    sort(all(v));

    for(pii x: v) {
        auto ptr = S.lower_bound(x.fi);

        if(ptr == S.end() or (*ptr) > x.se) continue;

        S.erase(ptr);
        ans++;
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
