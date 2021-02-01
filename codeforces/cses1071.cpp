// https://cses.fi/problemset/task/1071

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

int sq(int num) {
    return num*num;
}

void solve() {
    int r, c;
    cin >> r >> c;

    int ring = max(r, c);
    int len = 2*ring-1;

    int lo = sq(ring-1)+1;
    int hi = lo+len-1;

    int ind;
    watch(len)

    if(r >= c) {
        ind = c;
    } else {
        ind = ring+(ring-r);
    }

    watch(ind)
    watch(lo)
    watch(ring)

    if(ring%2 == 1) {
        // increasing
        
        cout << lo+ind-1 << endl;
    } else {
        // decreasing
       cout << hi-ind+1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
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
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
