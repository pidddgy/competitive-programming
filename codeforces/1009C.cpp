// https://codeforces.com/contest/1009/problem/C

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

void solve() {
    
}

int trng(int a) {
    return (a*(a+1))/2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(10);

    int n, m;
    cin >> n >> m;

    int mi = LLONG_MAX, ma = 0;

    // use i'th element, how much sum of distance
    for(int i = 1; i <= n; i++) {
        int l = i-1;
        int r = n-i;

        ma = max(ma, trng(l)+trng(r));
        mi = min(mi, trng(l)+trng(r));
    }

    int sum = 0;
    for(int i = 1; i <= m; i++) {
        int x, d;
        cin >> x >> d;

        watch(x*n)
        watch(d*ma);
        sum += x*n; // first term

        if(d < 0) {
            sum += d*mi;
        } else {
            sum += d*ma;
        }
    }

    ld ans = (ld)sum / n;
    cout << ans << endl;
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
