// https://codeforces.com/contest/622/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ld[n+1];
    ld[1] = -1;
    for(int i = 2; i <= n; i++) {
        if(a[i] != a[i-1]) {
            ld[i] = i-1;
        } else {
            ld[i] = ld[i-1];
        }
    }

    for(int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        if(a[r] != x) {
            cout << r << endl;
        } else if(ld[r] >= l) {
            cout << ld[r] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
