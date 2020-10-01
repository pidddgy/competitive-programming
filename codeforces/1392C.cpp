// https://codeforces.com/contest/1392/problem/C

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

const int maxn = 200500;

int a[maxn];
void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans =0;
    for(int i = 1; i <= n-1; i++) {
        ans += max(0LL, a[i]-a[i+1]);
    }
    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

for i from 1...n

when we see a decreasing element store a[i-1]

if at any point a[i+1] is greater than the element we stored we can raise them all up

1 2 3 4 2 4 1 1

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?