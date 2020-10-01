// https://codeforces.com/contest/1359/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define ld long double

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(10);
    cerr << setprecision(10);
    int T;
    cin >> T;

    while(T--) {
        int a, b, t;
        cin >> a >> b >> t;

        int lx, ly, rx, ry;
        lx = ly = rx = ry = 0;

        lx = t;
        ry = t;

        rx = a;
        ry = b;

        int maxx = max(lx, rx);
        int maxy = max(ly, ry);

        int minx = min(lx, rx);
        int miny = min(ly, ry);

        int x = maxx-minx;
        int y = maxy-miny;

        watch(x)
        watch(y)

        // x value = y/x

        ld minDis = LDBL_MAX;

        int xans = '?', yans = '?';
        for(int i = 1; i <= 10; i++) {
            ld thing = (ld)(y*i) / (ld)x;
            ld dis = min(thing-floor(thing), ceil(thing)-thing);

            // watch(thing-floor(thing))
            // watch(ceil(thing)-(thing))

            watch(thing)
            cerr << "dis for " << i << " is " << dis << endl;

            if(dis < minDis) {
                xans = floor(thing);
                yans = i;

                minDis = dis;
            }
            cerr << endl;
        }

        watch(xans)
        watch(yans)
        int g = gcd(xans, yans);
        cout << xans/g + yans/g << endl;
    }
}