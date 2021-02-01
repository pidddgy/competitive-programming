// https://codeforces.com/contest/1457/problem/C

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

int cost[maxn];
void solve() {
    int n, p, k;
    cin >> n >> p >> k;

    string a;
    cin >> a;

    a = "."+a;

    int x,y;
    cin >> x >> y;

    for(int i = n; i >= 1; i--) {
        if(a[i] == '0') cost[i] += x;
        if(i+k <= n) cost[i] += cost[i+k];
    }

    int ans = LLONG_MAX;
    int pre = 0;
    for(int i = p; i <= n; i++) {
        ans = min(ans, pre+cost[i]);
        pre += y;
    }

    cout << ans << endl;

    // clear everything
    for(int i = 1; i <= n; i++) {
        cost[i] = 0;
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

right side is fixed

brute force cost of making each


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
