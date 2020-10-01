// https://codeforces.com/contest/175/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // .fi = cost, .se = amount
    pii a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i].se >> a[i].fi;
    }

    sort(a+1, a+n+1);

    int t;
    cin >> t;

    int p[t+1];
    for(int i = 1; i <= t; i++) {
        cin >> p[i];
    }

    int des = 0, pts = 0, fac = 1;
    for(int i = 1; i <= n; i++) {
        watch(fac)
        watch(des)
        cerr << a[i].fi << " " << a[i].se << endl;
        while(des+a[i].se >= p[fac]) {
            int take = p[fac]-des;
            if(take > a[i].se) break;
            if(take < 0) break;
            assert(take <= a[i].se);
            watch(take)
            pts += take*a[i].fi*fac;
            cerr << "adding " << take*a[i].fi*fac << endl;
            des += take;
            a[i].se -= take;
            fac++;
            if(fac > t) break;
        }

        pts += a[i].se*a[i].fi*fac;
        cerr << "addinggg " << a[i].se*a[i].fi*fac << endl;
        des += a[i].se;
        cerr << endl;
    }

    cout << pts << endl;
}