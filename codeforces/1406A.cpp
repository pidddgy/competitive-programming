// https://codeforces.com/contest/1406/problem/0

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


int a[200];

void solve() {
    int n;
    cin >> n;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ans = 0;

    int need = 0;
    while(cnt[need]) {
        cnt[need]--;
        need++;
    }
    watch(need)
    ans += need;

    need = 0;
    while(cnt[need]) {
        cnt[need]--;
        need++;
    }
    ans += need;
    watch(need)

    cout << ans << endl;
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
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
