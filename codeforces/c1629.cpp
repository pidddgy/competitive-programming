// https://cses.fi/problemset/task/1629

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

const int maxn = 200500;

int n;
pii a[maxn];
int suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a+1, a+n+1);

    int mi = a[n].se;
    for(int i = n; i >= 1; i--) {
        mi = min(mi, a[i].se);

        suf[i] = mi;
    }

    int cur = 1;
    int took = 0;
    int ans = 0;

    while(cur <= n) {
        while(cur <= n and a[cur].fi < took) {
            cur++;
        }

        if(cur == n+1) break;

        took = suf[cur];
        ans++;
    }

    cout << ans << endl;
}

/*

take next possible movie that ends earliest

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
