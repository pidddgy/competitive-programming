// http://codeforces.com/contest/1169/problem/0

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int n, x, a, b, y;
    cin >> n >> a >> x >> b >> y;

    if(a == b) {
        cout << "YES" << endl;
        return 0;
    }

    for(;;) {
        a++;
        b--;

        if(a == n+1) a = 1;
        if(b == 0) b = n;

        if(a == b) {
            cout << "YES" << endl;
            return 0;
        }

        if(x == a || y == b) break;
    }

    cout << "NO" << endl;
}
