// https://codeforces.com/contest/910/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int ans = INT_MAX;
    // 1 == vertical, 0 == top
    for(int i = 0; i <= (1<<6)-1; i++) {
        int cost = 0;

        int vcnt = 0, tcnt = 0;
        int cur = 0;
        for(int j = 5; j >= 0; j--) {
            if(i&(1<<j)) {
                vcnt++;
                if(cur+a > n) {
                    cur = 0;
                    cost++;
                }
                cur += a;
            } else {
                tcnt++;
                if(cur+b > n) {
                    cur = 0;
                    cost++;
                }
                cur += b;
            }
        }
        if(cur) cost++;

        if(vcnt == 4 and tcnt == 2) {
            cerr << "cost for " << i << " is " << cost << endl;
            watch(cur)
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
}