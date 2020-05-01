// https://codeforces.com/contest/379/problem/C

#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
signed main() {
    int n;
    cin >> n;

    pii a[n+1];
    set<int> have;
    for(int i = 1; i <= n; i++) {
        int _;
        cin >> _;

        have.emplace(_);

        a[i] = make_pair(_, i);
    }

    sort(a+1, a+n+1);

    int ans[n+1];
    int upto = 0;
    for(int i = 1; i <= n; i++) {
        if(upto >= a[i].fi) {
            ans[a[i].se] = upto+1;
            upto++;
        } else {
            ans[a[i].se] = a[i].fi;
            upto = a[i].fi;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}