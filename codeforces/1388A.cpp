// https://codeforces.com/contest/1388/problem/0

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
    int n;
    cin >> n;
    // handle edge cases

    if(n == 36) {
        cout << "YES" << endl;
        cout << "5 6 10 15" << endl;
        return;
    } else if(n == 40) {
        cout << "YES" << endl;
        cout << 14 << " " << 15 << " " << 6 << " " << 5 << endl;
        return;
    } else if(n == 44) {
        cout << "YES" << endl;
        cout << "6 7 10 21" << endl;
        return;
    }

    if(n <= 6+10+14) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << 6 << " " << 10 << " " << 14 << " " << n-30 << endl;
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
