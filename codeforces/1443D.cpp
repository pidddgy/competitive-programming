// https://codeforces.com/contest/1443/problem/D

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

const int maxn = (int)1e6+500;

int cpy[maxn];
int a[maxn];

int n;
void reset() {
    for(int i = 1; i <= n; i++) {
        a[i] = cpy[i];
    }
}

void solve() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> cpy[i];
        reset();
    }

    string ans = "NO";

    // make it non increasing (go down)
    // each element becomes prefix min if it is greater
    int mi = LLONG_MAX;
    int sub = 0;
    bool ok = true;
    for(int i = 1; i <= n; i++) {
        sub = max(sub, a[i]-mi);
        a[i] -= sub;

        if(a[i] < 0) ok = false;
        mi = min(mi, a[i]);
    }

    if(ok) ans = "YES";

    // make it non decreasing (go up)
    reset();
    reverse(a+1, a+n+1);
    mi = LLONG_MAX;
    sub = 0;
    ok = true;
    for(int i = 1; i <= n; i++) {
        sub = max(sub, a[i]-mi);
        a[i] -= sub;

        if(a[i] < 0) ok = false;
        mi = min(mi, a[i]);
    }

    if(ok) ans = "YES";

    

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

to decrement an element we either need to subtract from its prefix or suffix

subproblem: only allowed prefix
-> must be in non decreasing order

try to make it monotonic

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
