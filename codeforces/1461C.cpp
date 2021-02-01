// https://codeforces.com/contest/1461/problem/C

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
    int n, m;
    cin >> n >> m;

    int last = -1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if(i != x) last = i;
    }

    ld allbad = 1;

    for(int i = 1; i <= m; i++) {
        int r;
        ld p;
        cin >> r >> p;

        if(r >= last) {
            allbad *= (1.0 - p); 
        }
    }

    if(last == -1) allbad = 0;

    cout << 1-allbad << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

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
