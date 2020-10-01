// https://codeforces.com/problemset/problem/1426/E

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

int a[5], b[5];
int ca[5], cb[5];
int mod(int n) {
    return (n+9)%3;
}
void solve() {
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }

    for(int i = 0; i < 3; i++) {
        cin >> b[i];
    }

    vector<pii> p;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            p.emplace_back(i, j);
        }
    }

    sort(all(p));
    int mi = LLONG_MAX, ma = LLONG_MIN;
    do {
        // cerr << "trying " << endl;
        // for(pii x: p) {
        //     cout << x.fi << " " << x.se << endl;
        // }
        for(int i = 0; i < 3; i++) {
            ca[i] = a[i];
            cb[i] = b[i];
        }

        int aw = 0;

        for(pii x: p) {
            int take = min(ca[x.fi], cb[x.se]);

            if(mod(x.fi+1) == x.se) {
                aw += take;
            }

            ca[x.fi] -= take;
            cb[x.se] -= take;
        }

        mi = min(mi, aw);
        ma = max(ma, aw);
    } while(next_permutation(all(p)));

    cout << mi << " " << ma << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    solve();
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
