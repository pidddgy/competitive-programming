// https://codeforces.com/contest/1369/problem/B

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

        string s;
        cin >> s;

        s = "."+s;

        int f1 = -1, l0 = -1;
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1' and f1 == -1) {
                f1 = i;
            }
            if(s[i] == '0') {
                l0 = i;
            }
        }

        if(l0 > f1 and (l0 != -1) and (f1 != -1)) {
            for(int i = 1; i <= n; i++) {
                if(i < f1 or i >= l0) {
                    cout << s[i];
                }
            }

            cout << endl;
        } else {
            for(int i = 1; i <= n; i++) {
                cout << s[i];
            }

            cout << endl;
        }
    }
}
