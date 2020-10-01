// https://codeforces.com/contest/1396/problem/B

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

const int maxn = 105;
int n;
int a[maxn];

void solve() {
    cin >> n;
    int sum = 0, ma = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        ma = max(ma, a[i]);
    }    

    if(ma > sum/2) {
        cout << "T" << endl;
    } else if(sum%2 == 0) {
        cout << "HL" << endl;
    } else {
        cout << "T" << endl;
    }
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
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
