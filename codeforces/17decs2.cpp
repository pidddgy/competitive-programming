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

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n, g;
    cin >> n >> g;
    vector<pair<int, pii>> v;

    multiset<int> S;
    map<int, int> mp;
    set<int> ids;
    for(int i = 1; i <= n; i++) {
        int t, id, incr;
        cin >> t >> id >> incr;
        ids.emplace(id);

        if(mp[id] == 0) S.emplace(g);
        mp[id] = g;
        v.emplace_back(t, pii(id, incr));
    }

    for(int i = 3e5; i <= 5e5; i++) {
        if(!ids.count(i)) {
            S.emplace(g);
            mp[i] = g;
        }
    }

    sort(all(v));
    int cur = g;
    int cnt = S.count(g);
    int ans = 0;

    for(auto x: v) {
        pii p = x.se;
        // cerr << p.fi << " " << p.se << endl;

        int old = mp[p.fi];
        S.erase(S.lower_bound(old));

        int nxt = old+p.se;


        mp[p.fi] = nxt;
        S.emplace(nxt);

        int ma = *S.rbegin();
        int c = S.count(ma);

        // the only case where leaderboard stays the same is if there is only one cow and it stays the same
        if((old == cur or nxt >= cur) and !(cnt == 1 and old == cur and c == 1 and ma == nxt)) {
            ans++;
        }

        cur = ma;
        cnt = c;
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
