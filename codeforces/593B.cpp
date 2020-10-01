// https://codeforces.com/contest/593/problem/B

using namespace std;
#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define cerr if(false) cerr
#define endl '\n'
#define int long long
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second

struct Compare {
     bool operator()(pii &l, pii &r) {
        if(min(l.fi, l.se) == min(r.fi, r.se)) {
            return max(l.fi, l.se) < max(r.fi, r.se);
        } else {
            return min(l.fi, l.se) < min(r.fi, r.se); 
        }
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int x1, x2;
    cin >> x1 >> x2;

    int k[n+1], b[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> k[i] >> b[i];
    }

    watch(k[1]*x1 + b[1])

    vector<pii> all;
    for(int i = 1; i <= n; i++) {
        cerr << "on " << k[i] << " " << b[i] << endl;
        int f = (k[i]*x1) + b[i];
        int s = (k[i]*x2) + b[i];

        cerr << f << "," << s << endl;

        all.emplace_back(pii(f, s));
    }

    sort(all.begin(), all.end(), Compare());

    for(int i = 0; i < all.size()-1; i++) {
        int imi = min(all[i].fi, all[i].se);
        int ima = max(all[i].fi, all[i].se);
        int nmi = min(all[i+1].fi, all[i+1].se);
        int nma = max(all[i+1].fi, all[i+1].se);

        if((all[i].fi == all[i+1].fi) or (all[i].se == all[i+1].se)) {
            cerr << "one is same" << endl;
            continue;
        }

        if(not ((all[i].fi < all[i+1].fi) ^ (all[i].se < all[i+1].se))) {
                cerr << "stopped" << endl;
                continue;
        }

        if(imi < nma and ima > nmi) {
            cout << "YES" << endl;
            return 0;
        }

        

        // // effectively parallel / might be same y values but don't intersect
        // if(all[i].fi < all[i+1].fi and all[i].se < all[i+1].se) {
        //     cerr << "stopped" << endl;
        //     continue;
        // }
        // if(all[i].fi < all[i+1].se and all[i].se > all[i+1].fi) {
        //     cout << "YES" << endl;
        //     return 0;
        // } else if (all[i] == all[i+1]) {
        //     cout << "YES" << endl;
        //     return 0;
        // }
    }

    cout << "NO" << endl;
}
