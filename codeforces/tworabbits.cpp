// https://codeforces.com/contest/1304/problem/0

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int T;
    cin >> T;

    while(T--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        int l = 1;
        int r = 2005000000;
        int good = -1;
        while(l <= r) {
            int m = (l+r)/2;

            watch(m)

            int bigger = x+(a*m);
            int smaller = y-(b*m);

            if(smaller == bigger) {
                good = m;
                break;
            }

            if(smaller < bigger) {
                // cerr << " too big " << endl;
                r = m-1;
            } else {
                l = m+1;
            }
        }

        if(good != -1) {
            cout << good << endl;
        } else {
            cout << - 1 << endl;
        }
    }
}