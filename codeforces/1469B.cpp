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

const int maxn = 105;

int a[3*maxn];
void solve() {
    int n, m;

    int r = 0, b = 0;

    cin >> n;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        cur += x;

        r = max(r, cur);
        cerr << cur << " ";
    }
    cerr << endl;

    cin >> m;
    cur = 0;
    for(int i = 1; i <= m; i++) {
        int x;
        cin>> x;

        cur += x;

        b = max(b, cur);
    }

    cerr << r << " " << b << endl;
    cout << r+b << endl;
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
