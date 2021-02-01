// https://codeforces.com/contest/1146/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

vector<int> query;
void pr() {
    for(int x: query) {
        cout << x << " ";
    }
    cout << endl;
    cout.flush();
}
void solve() {
    int n;
    cin >> n;

    int l = 2;
    int r = n;

    int v = -1;
    // cerr <<

    query = {1, n-1, 1};
    for(int i = 2; i <= n; i++) {
        query.emplace_back(i);
    }

    pr();

    int last;
    cin >> last;

    while(l < r) {
        int mid = (l+r)/2;

        // cout << 1 << " " << mid-l+1 << " 1 ";
        query = {1, mid-l+1, 1};
        for(int i = l; i <= mid; i++) {
            // cout << i << " ";
            query.emplace_back(i);
        }
        // cout << endl;
        pr();

        int ql;
        cin >> ql;

        if(ql == -1) exit(0);

        // correct node is on left side
        if(ql == last) {
            v = mid;
            r = mid;
        } else {
            v = mid+1;
            l = mid+1;
        }
    }

    v = l;
    // assert(v != -1);

    // cout << v << endl;
    // cout << 1 << " " << n-1 << " " << v << " ";
    query = {1, n-1, v};
    for(int i = 1; i <= n; i++) {
        // if(i != v) cout << i << " ";
        if(i != v) query.emplace_back(i);
    }
    pr();
    // cout << endl;

    int ans;
    cin >> ans;
    if(ans == -1) exit(0);

    cout << -1 << " " << ans << endl;
    cout.flush();
}

signed main() {
    int t;
    cin >> t;

    while(t--) solve();
}

/*
99 -> 49 -> 25 -> 13 -> 7 -> 4 -> 2 -> 1
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
