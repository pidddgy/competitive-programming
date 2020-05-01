// https://codeforces.com/contest/1080/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define int long long
#define endl '\n'

int cntblack(int x, int y, int a, int b) {
    int area = (abs(x-a)+1) * (abs(y-b)+1);

    if((x%2==0)^(y%2==0)) {
        return (area+1)/2;
    } else {
        return area/2;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        int x1, y1, x2, y2;
        int x3, y3, x4, y4;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x3 >> y3 >> x4 >> y4;

        int blk = cntblack(1, 1, n, m);
        
        blk -= cntblack(x1, y1, x2, y2);

        int ix1 = max(x1, x3);
        int iy1 = max(y1, y3);

        int ix2 = min(x2, x4);
        int iy2 = min(y2, y4);

        if(!(ix1 > ix2 or iy1 > iy2))
        blk += cntblack(ix1, iy1, ix2, iy2);

        int blackarea = (abs(x3-x4)+1) * (abs(y3-y4)+1);

        blk += blackarea - cntblack(x3, y3, x4, y4);

        cout << n*m-blk << " " << blk << endl; endl;
    }
}