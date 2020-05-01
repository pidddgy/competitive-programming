// http://m1.codeforces.com/contest/1332/problem/A

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        int xchange = b - a;
        int ychange = d - c;

        int newx = x+xchange;
        int newy = y+ychange;
        if(x2-x1 <= 0) {
            if(a >= 1 or b >= 1) {
                cout << "NO" << endl;
                continue;
            }
        }

        if(y2-y1 <= 0) {
            if(c >= 1 or d >= 1) {
                cout << "NO" << endl;
                continue;
            }
        }
        if(x1 <= newx and newx <= x2) {
            if(y1 <= newy and newy <= y2) {
                cout << "YES" << endl;
                continue;
            }
        }

        cout << "NO" << endl;

    }
}