// https://codeforces.com/contest/1260/problem/C

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
    int r, b, k;
    cin >> r >> b >> k;

    int g = __gcd(r, b);

    r /= g;
    b /= g;

    if(r > b) swap(r, b);

    // Assume some posiition where r = b+1
    // Check if k'th red plank is before the next blue plank or not
    if((k-1)*r + 1 < b) {
        // Too many
        cout << "REBEL" << endl;
    } else {
        cout << "OBEY" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) solve();
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
