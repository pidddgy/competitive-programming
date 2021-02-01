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

    int o = 0, t = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        if(x == 1) o++;
        else t++;
    }

    for(int i = 0; i <= o; i++) {
        for(int j = 0; j <= t; j++) {
            if(i + 2*j == (o-i) + (2*(t-j))) {
                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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
