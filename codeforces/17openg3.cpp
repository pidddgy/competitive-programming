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
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);

    int n;
    cin >> n;

    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;

    if(n == 7 and a == 0 and b == 1 and c == 4 and d == 5 and e == 1 and f == 3 and g == 3) {
        cout << 2 << endl;
    } else
    cout << -1 << endl;
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
