// https://codeforces.com/contest/190/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ld long double

ld dist(int x, int y, int a, int b) {
    return sqrtl(powl(abs(x-a), 2) + powl(abs(b-y), 2));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);

    int x, y, r;
    cin >> x >> y >> r;

    int x2, y2, r2;
    cin >> x2 >> y2 >> r2;

    // intersect
    if(abs(r-r2) <= dist(x, y, x2, y2) and dist(x, y, x2, y2) <= r+r2) {
        cout << 0 << endl;
    } else if(dist(x, y, x2, y2) + min(r, r2) <= max(r, r2)) { // fully inside 
        cout << ((ld)max(r, r2) - dist(x, y, x2, y2) - min(r, r2)) / 2.0 << endl;
    } else {
        cout << (dist(x, y, x2, y2) - r - r2)/2.0 << endl;
    }


}