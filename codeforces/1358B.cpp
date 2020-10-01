// https://codeforces.com/contest/1358/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);

        int ma = 0;
        int best = 0;
        for(int i = 1; i <= n; i++) {
            ma = max(ma, a[i]);

            if(ma <= i) {
                best = i;
            }
        }

        cout << best+1 << endl;
    }
}
