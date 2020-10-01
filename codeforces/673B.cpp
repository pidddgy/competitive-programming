// https://codeforces.com/contest/673/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

set<int> div1, div2;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;

        div1.emplace(max(x, y));
        div2.emplace(min(x, y));
    }

    if(div1.size()+div2.size() > n) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 1;

    for(int i = 1; i <= n; i++) {
        if(div1.count(i) or div2.count(i)) continue;

        int d2, d1;
        if(div2.empty()) {
            d2 = 0;
        } else {
            d2 = *div2.rbegin();
        }

        if(div2.empty()) {
            d1 = INT_MAX;
        } else {
            d1 = *div1.rbegin();
        }

        if(i > d2 and i < d1) {
            ans++;
        }
    }

    cout << ans << endl;
}