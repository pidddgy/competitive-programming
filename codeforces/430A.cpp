// https://codeforces.com/contest/430/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    pii a[n+1];
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;

        a[i] = pii(val, i);
    }
    sort(a+1, a+n+1);

    int ans[n+1];
    for(int i = 1; i <= n; i++) {
        // cerr << "currently on " << a[i].fi << "," << a[i].se << endl;
        ans[a[i].se] = (1?(i%2):0);
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}