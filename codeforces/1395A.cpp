// https://codeforces.com/contest/1395/problem/0

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
int r, g, b, w;

bool check() {
    int cnt = 0;
    if(r & 1) cnt++;
    if(g & 1) cnt++;
    if(b & 1) cnt++;
    if(w & 1) cnt++;

    return (cnt <= 1);
}

void solve() {
    cin >> r >> g >> b >> w;

    if(check()) {
        cout << "Yes" << endl;
        return;
    }

    if(r and g and b) {
        r--;
        g--;
        b--;
        w += 3;
    }

    if(check()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
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
