// http://codeforces.com/contest/1196/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        int xlower = -100000;
        int xupper = 100000;

        int ylower = -100000;
        int yupper = 100000;

        for(int i = 0; i < n; i++) {
            int x, y, f1, f2, f3, f4;
            cin >> x >> y >> f1 >> f2 >> f3 >> f4;

            // at least
            if(f1 == 0) {
                xlower = max(xlower, x);
            }

            if(f2 == 0) {
                yupper = min(yupper, y);
            }

            if(f3 == 0) {
                xupper = min(xupper, x);
            }

            if(f4 == 0) {
                ylower = max(ylower, y);
            }
        }

        // watch(xlower)
        // watch(xupper)
        // watch(ylower)
        // watch(yupper)

        if(xlower > xupper || ylower > yupper) {
            cout << 0 << endl;
        } else {
            cout << 1 << " " << xlower << " " << ylower << endl;
        }
    }
}