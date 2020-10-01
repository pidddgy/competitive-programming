// https://codeforces.com/contest/1399/problem/C

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
    int n;
    cin >> n;

    int a[n+1];
    a[0] = 0;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }    

    int ans = 0;
    // CHANGE WHEN SUBMIT
    for(int s = 1; s <= 100; s++) {
        // cerr << "trying " << s << endl;
        int loc = 0;
        int ree = 0;
        for(int j = 1; j <= n; j++) {
            // watch(j)
            if(j*2 == s) {
                // cerr << "adding " << cnt[j]/2 << endl;
                loc += cnt[j]/2;
            } else {
                // cerr << "adding " << cnt[j], cnt[s-j] << endl;
                ree += min(cnt[j], cnt[s-j]);
            }
        }

        assert(ree % 2 == 0);

        // the different pairs get double counted
        loc += ree/2;

        ans = max(ans, loc);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
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
