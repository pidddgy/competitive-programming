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

const int maxn = 55;

int n;
int a[maxn];

void solve() {
    cin >> n;

    vector<int> v(2);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        v[i%2] += a[i];
    }

    if(v[1] < v[0]) {
        for(int i = 1; i <= n; i++) {
            int x = 1;
            if(i&1) {
                x = 1;
            } else {
                // cout << a[i] << " ";
                x = a[i];
            }

            cout << x << " ";
        }

        cout << endl;
    } else {
        for(int i = 1; i <= n; i++) {
            int x = 1;
            if(i&1) {
                x = a[i];
            } else {
                // cout << a[i] << " ";
                x = 1;
            }

            cout << x << " ";
        }

        cout << endl;
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
