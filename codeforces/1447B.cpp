// https://codeforces.com/contest/1447/problem/B

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

int a[200][200];

void solve() {
    int n, m;
    cin >> n >> m;

    int sum = 0, mi = LLONG_MAX;
    int pos = 0, neg = 0, z = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 0) z++;
            else if(a[i][j] > 0) pos++;
            else neg++;

            sum += abs(a[i][j]);
            mi = min(mi, abs(a[i][j]));
        }
    }

    if(!z and (neg)%2) {
        sum -= 2*mi;
    }

    cout << sum << endl;
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

parity never changes unless there is zero

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
