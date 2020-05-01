// https://codeforces.com/contest/1341/problem/0

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        int lo = n*(a-b);
        int hi = n*(a+b);

        int l = c-d;
        int r = c+d;

        if(hi >= l and lo <= r) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
}