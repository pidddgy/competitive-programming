// https://codeforces.com/contest/1362/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        set<int> S;
        for(int i = 1; i <= n; i++) {
            int s;
            cin >> s;

            S.emplace(s);
        }

        int ans = -1;
        for(int i = 2000; i >= 1; i--) {
            set<int> n;

            for(int x: S) {
                n.emplace(x^i);
            }

            if(n == S) {
                ans = i;
            }
        }

        cout << ans << endl;
    }
}
