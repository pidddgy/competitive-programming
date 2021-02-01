#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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
    int n;
    cin >> n;

    vector<int> shit;
    map<int, int> ind;

    vector<pii> a(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;

        shit.emplace_back(a[i].fi);
        shit.emplace_back(a[i].se);
    }    

    sort(all(shit));
    shit.erase(unique(all(shit)), shit.end());

    map<int, int> mp;

    for(int i = 0; i < sz(shit); i++) {
        mp[shit[i]] = i+1;
    }

    vector<int> st(sz(shit)+500);
    vector<int> en(sz(shit)+500);

    for(int i = 1; i <= n; i++) {
        st[mp[a[i].fi]]++;
        en[mp[a[i].se]]++;
    }

    for(int i = 1; i < sz(shit)+500; i++) {
        st[i] += st[i-1];
        en[i] += en[i-1];
    }

    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        int loc = n;

        loc -= st[mp[a[i].se]] - en[mp[a[i].fi]-1];

        ans = min(ans, loc);
    }

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

for each l, r

start <= r - end < l
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?