// https://codeforces.com/contest/1451/problem/D

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
int d, k;

bool ok(int p, int q) {
    return (p*p + q*q <= d*d);
}
void solve() {
    cin >> d >> k;

    int p = 0, q = 0;
    bool awin = false;

    for(int i = 0;; i++) {
        if(i%2 == 0) {
            if(ok(p+k, q)) {
                p += k;
            } else if(ok(p, q+k)) {
                q += k;
            } else break;
        } else {
            if(ok(p, q+k)) {
                q += k;
            } else if(ok(p+k, q)) {
                p += k;
            } else break;
        }

        awin ^= 1;
    }

    // watch(p)
    // watch(q)
    if(awin) {
        cout << "Ashish" << endl;
    } else {
        cout << "Utkarsh" << endl;
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

loop from n to 1



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
