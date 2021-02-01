// https://codeforces.com/contest/1427/problem/0

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
    vector<int> v;
    int sum = 0;
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        v.push_back(x);
        sum += x;
    }

    if(sum == 0) {
        cout << "NO" << endl;
        return;
    }

    sort(all(v));
    sum = 0;
    bool ok = true;
    for(int x: v) {
        sum += x;

        if(sum == 0) ok = false;
    }

    if(ok) {
        cout << "YES" << endl;
        for(int x: v) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    reverse(all(v));
    
    sum = 0;
    ok = true;

    for(int x: v) {
        sum += x;

        if(sum == 0) ok = false;
    }

    if(ok) {
        cout << "YES" << endl;
        for(int x: v) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    assert(false);
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
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
