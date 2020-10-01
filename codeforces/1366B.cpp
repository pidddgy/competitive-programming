// https://codeforces.com/contest/1366/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
const int maxm = 105;
int l[maxm], r[maxm];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, x, m;
        cin >> n >> x >> m;

        for(int i = 1; i <= m; i++) {
            cin >> l[i] >> r[i];
        }

        int ans = 1;

        // intersection
        int lb = l[1], rb = r[1];
        bool haveX = false;

        if(l[1] <= x and x <= r[1]) {
            haveX = true;
            ans = max(ans, rb-lb+1);
        }

        // watch(haveX)
        for(int i = 2; i <= m; i++) {
            if(haveX) {
                ans = max(ans, rb-lb+1);
            } else {
                lb = l[i];
                rb = r[i];
            }

            if(l[i] <= x and x <= r[i]) {
                haveX = true;
            }

            // if we can merge
            if(l[i] <= rb and r[i] >= lb) {
                lb = min(lb, l[i]);
                rb = max(rb, r[i]);
            } 

            if(haveX) {
                ans = max(ans, rb-lb+1);
            }
        }

        cout << ans << endl;

        for(int i = 1; i <= m; i++) {
            l[i] = r[i] = 0;
        }
    }
}
