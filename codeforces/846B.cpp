// https://codeforces.com/contest/846/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define ll long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, k, M;
    cin >> n >> k >> M;

    ll t[k+1];
    ll sum = 0;
    for(ll i = 1; i <= k; i++) {
        cin >> t[i];
        sum += t[i];
    }

    sort(t+1, t+k+1);

    ll ans = 0;
    // do i full tasks
    for(ll i = 0; i <= n; i++) {
        watch(i)
        ll cost = sum*i;
        ll pts = (k+1)*i;
        watch(pts)

        ll rem = M-cost;
        if(rem < 0) continue;

        assert(rem >= 0);
        for(ll j = 1; j <= k; j++) {
            if(rem == 0) break;

            cerr << "adding " << min(n-i, rem / t[j]) << " from " << j << endl; 
            pts += min(n-i, rem / t[j]);
            rem -= t[j] * min(n-i, rem / t[j]);
            watch(rem)
            assert(rem >= 0);
        }
        assert(rem >= 0);

        watch(pts)

        ans = max(ans, pts);
        cerr << endl;
    }

    cout << ans << endl;
}