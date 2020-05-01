// https://codeforces.com/contest/538/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pii a[m+1];
    for(int i = 1; i <= m; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    int ans = 0;
    ans = max(ans, a[1].fi-1 + a[1].se);
    ans = max(ans, n-a[m].fi + a[m].se);

    for(int i = 1; i <= m-1; i++) {
        if(abs(a[i].se-a[i+1].se) > abs(a[i].fi-a[i+1].fi)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        int l = 0;
        int r = a[i+1].fi-a[i].fi;
        int lastgood = -1;

        while(l <= r) {
            int m = (l+r)/2;
            watch(m)
            int peakVal = a[i].se+m;
            cerr << "peak val is " << a[i].se+m;
            cerr << "will hit peak at " << a[i].fi+m << endl;

            if(peakVal - a[i+1].se <= a[i+1].fi-(a[i].fi+m)) {
                lastgood = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        watch(lastgood)
        if(lastgood != -1)
        ans = max(ans, a[i].se+lastgood);
    }

    cout << ans << endl;
}