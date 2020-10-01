// https://codeforces.com/contest/1379/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;

    pii f[m+1];
    for(int i = 1; i <= m; i++) {
        cin >> f[i].fi >> f[i].se;
    }

    sort(f+1, f+m+1, greater<pii>());

    int psa[m+1];
    for(int i = 0; i < m+1; i++) {
        psa[i] = 0;
    }

    for(int i = 1; i <= m; i++) {
        psa[i] = psa[i-1] + f[i].fi;
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) {
        int loc = f[i].fi;
        int rem = n-1;

        // Grab all optimal f values from 1...i-1
        int l = 1;
        int r = min({rem, m, i-1});
        int lgood = 0;

        while(l <= r) {
            int mid = (l+r)/2;

            if(f[mid].fi >= f[i].se) {
                lgood = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        loc += psa[lgood];
        rem -= lgood;

        // Grab all optiaml f values from i+1...m
        l = i+1;
        r = min({i+rem, m});
        lgood = i;

        while(l <= r) {
            int mid = (l+r)/2;

            if(f[mid].fi >= f[i].se) {
                lgood = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        loc += psa[lgood] - psa[i];
        rem -= lgood-i;

        loc += rem*f[i].se;

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

    while(t--) {
        solve();
    }
}