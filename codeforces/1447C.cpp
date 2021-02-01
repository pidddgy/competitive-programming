// https://codeforces.com/contest/1447/problem/C

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

int a[200500];
void solve() {
    int n, W;
    cin >> n >> W;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> v;
    for(int i = 1; i <= n; i++) {
        if(a[i] > W) continue;

        if(a[i] >= ((W+1))/2) {
            cout << 1 << endl;
            cout << i << endl;
            return;
        }

        v.emplace_back(i);
    }

    int sum = 0;
    vector<int> out;

    for(int i: v) {
        sum += a[i];
        out.emplace_back(i);

        if(sum >= ((W+1))/2) break;
    }

    if(sum >= ((W+1))/2) {
        cout << sz(out) << endl;
        for(int i: out) {
            cout << i << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
        // cout << endl;
    }
}

/*

W <= 10^14, if not print no

any items > W are useless
any item that fits condition is printed

so all items are < W/2

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
