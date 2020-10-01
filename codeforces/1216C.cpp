// https://codeforces.com/contest/1216/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
int area(int x1, int y1, int x2, int y2) {
    watch(x1)
    watch(y1)
    watch(x2)
    watch(y2)
    cerr << "Returning " << abs(x1-x2) * abs(y1-y2) << endl;
    return abs(x1-x2) * abs(y1-y2);
}

int intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int x5 = max(x1, x3);
    int y5 = max(y1, y3);

    watch(y1)
    watch(y3)
    cerr << "bot left is " << x5 << "," << y5 << endl;

    int x6 = min(x2, x4);
    int y6 = min(y2, y4);

    cerr << "top right is " << x6 << "," << y6 << endl;


    if(x5 > x6 or y5 > y6) {
        cerr << "returning 0" << endl;
        return 0;
    }

    return area(x5, y5, x6, y6);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;

    int i1 = intersect(x1, y1, x2, y2, x3, y3, x4, y4);
    int i2 = intersect(x1, y1, x2, y2, x5, y5, x6, y6);

    int dbblx = max(x3, x5);
    int dbbly = max(y3, y5);

    int dbtrx = min(x4, x6);
    int dbtry = min(y4, y6);
    int ib = intersect(x1, y1, x2, y2, dbblx, dbbly, dbtrx, dbtry);

    watch(i1)
    watch(i2)
    watch(ib)

    if((i1 + i2) - ib >= area(x1, y1, x2, y2)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    // int sub = 0;
    // // intersection of black
    // int x7 = max(x3, x5);
    // int y7 = max(y3, y5);

    // int x8 = min(x4, y6);
    // int y8 = min(y4, y6);

    

}