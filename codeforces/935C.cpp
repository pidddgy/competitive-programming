// https://codeforces.com/contest/935/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ld long double

ld dist(ld x, ld y, ld a, ld b) {
    return sqrtl(powl(abs(x-a), 2) + powl(abs(b-y), 2));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);

    ld R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;

    ld dis = dist(x1, y1, x2, y2);
    if(dis > R) {
        cout << x1 << " " << y1 << " " << R << endl;
    } else {
        ld r = (dis+R)/2;
        ld x, y;
        
        if(x1 == x2 and y1 == y2) {
            x = x1+r;
            y = y1;
        } else {
            x = x2 - r*((x2-x1)/dis);
            y = y2 - r*((y2-y1)/dis);
        }

        cout << x << " " << y << " " << r << endl;
    }

    
}