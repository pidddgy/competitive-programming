// https://codeforces.com/contest/1096/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ld long double

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // for(int i = 3; i <= 50; i++) {
    //     int angle = ((180*(i-2))/i) / (i-2);

    //     cout << i << " - " << ((180*(i-2))/i)<< endl;
    // }
    int t;
    cin >> t;

    while(t--) {
        ld n;
        cin >> n;

        for(int i = 3; i <= 420; i++) {
            ld tot = ((ld)(180*(i-2))/(ld)i);
            ld angle = tot / ((ld)(i-2));
            cout << fixed << setprecision(20);
            // cout << "i is " << i << endl;
            // cout << "total is " << ((ld)(180*(i-2))/(ld)i) << endl;
            // cout << "angle is " << fixed << setprecision(5) << angle << endl;

            if(abs(remainder(n, angle)) < (ld)1e-5 and tot >= n) {
                cout << i << endl;
                break;
            }
            // cout << endl;
        }
    }
}