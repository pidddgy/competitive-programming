// https://codeforces.com/problemset/problem/1252/H

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

const int maxn = 100500;

int n;
pii a[maxn];
set<int> S;
int ans = 0;
ld ans2 = 0;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(1);
    cerr << fixed << setprecision(1);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;

        if(a[i].fi > a[i].se) {
            swap(a[i].fi, a[i].se);
        }
        ans2 = max(ans2, ((ld)a[i].fi*a[i].se) / 2.0);
    }

    watch(ans2)

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    int ma = 0;
    for(int i = 1; i <= n; i++) {
        cerr << a[i].fi << " " << a[i].se << endl;
        ans = max(ans, a[i].fi*min(ma, a[i].se));
        ma = max(ma, a[i].se);
    }

    ld ree = ans;

    cout << max(ree, ans2) << endl;
}

/*

reduce equation. assume a thing and then see if we can make that thing true

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
