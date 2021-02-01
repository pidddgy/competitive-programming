// https://codeforces.com/contest/1457/problem/B

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


const int maxn = 100500;
int n, k;

int a[maxn];

void solve() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = LLONG_MAX;
    for(int c = 1; c <= 102; c++) {
        // paint all c

        int loc = 0;
        int i =1;
        while(i <= n) {
            if(a[i] != c) {
                i += k;
                loc++;
            } else {
                i++;
            }
        }

        ans = min(ans, loc);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
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
