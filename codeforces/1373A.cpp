// https://codeforces.com/contest/1373/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int x = -1, y = -1;
        if(a < c) {
            x = 1;
        }

        if(c < (b*a)) {
            y = b;
        }

        cout << x << " " << y << endl;
    }
}
