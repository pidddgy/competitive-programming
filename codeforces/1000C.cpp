// https://codeforces.com/contest/1000/problem/C

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
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> m;

    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;

        m[l]++;
        m[r+1]--;
    }

    vector<pii> events;
    for(pii x: m) events.emplace_back(x);

    map<int, int> ans;
    int cur = 0;
    for(int i = 0; i < events.size(); i++) {
        if(i > 0) {
            ans[cur] += events[i].fi - events[i-1].fi;
        }
        cur += events[i].se;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

push segments into events

iterate over all events, if state 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
