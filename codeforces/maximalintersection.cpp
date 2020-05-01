// https://codeforces.com/contest/1029/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    pii a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }    

    int pl[n+5];
    int pr[n+5];

    int sl[n+5];
    int sr[n+5];

    for(int i = 0; i < n+5; i++) {
        pl[i] = INT_MIN;
        sl[i] = INT_MIN;

        pr[i] = INT_MAX;
        sr[i] = INT_MAX;
    }

    for(int i = 1; i <= n; i++) {
        pl[i] = max(pl[i-1], a[i].fi);
        pr[i] = min(pr[i-1], a[i].se);
    }

    for(int i = n; i >= 1; i--) {
        sl[i] = max(sl[i+1], a[i].fi);
        sr[i] = min(sr[i+1], a[i].se);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, min(sr[i+1], pr[i-1]) - max(pl[i-1], sl[i+1]));
    }

    cout << ans << endl;
}