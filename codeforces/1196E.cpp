// https://codeforces.com/contest/1196/problem/E

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

const vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int color(pii p) {
    int r = p.fi, c = p.se;
    if(r&1) {
        if(c&1) return 0;
        else return 1;
    } else {
        if(c&1) return 1;
        else return 0;
    }
}

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);

void solve(int b, int w) {

    int bcpy = b, wcpy = w;
    // int b, w;
    // cin >> b >> w;

    vector<pii> ans;

    vector<pii> add;
    
    // we need more blacks
    if(b > w) {
        // add.emplace_back(2, 1);
        ans.emplace_back(2, 1);
        b--;
    }
    int j = 2;
    for(int i = 1; i <= min(b, w); i ++) {
        ans.emplace_back(2, j); // white
        ans.emplace_back(2, j+1); // black

        // we need more whites
        if(w > b) {
            add.emplace_back(2, j+1);
        } else if(b > w) { // need more blacks
            add.emplace_back(2, j);
        }

        j += 2;
    }

    // we need more whites
    if(w > b) {
        // add.emplace_back(2, j);
        ans.emplace_back(2, j);
        w--;
    }

    int added = 0;
    watch(sz(add))

    for(pii x: add) {
        cerr << x.fi << " " << x.se << endl;
        if(added < abs(b-w)) {
            ans.emplace_back(x.fi-1, x.se);
            added++;
        }

        if(added < abs(b-w)) {
            ans.emplace_back(x.fi+1, x.se);
            added++;
        }
    }

    vector<int> cnt(2);
    for(pii x: ans) { 
        cnt[color(x)]++;
    }
    if(cnt[0] != wcpy or cnt[1] != bcpy) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se;
        cout << endl;

    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        int b, w;
        cin >> b >> w;
        solve(b, w);
    }
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
