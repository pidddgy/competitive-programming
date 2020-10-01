// https://codeforces.com/contest/712/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

bool ok(int a, int b, int c) {
    if(a+b <= c) return false;
    if(c+a <= b) return false;
    if(b+c <= a) return false;

    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> x >> y;

    int a=y, b=y, c=y;

    int ans = 0;
    while(true) {
        if(a >= x and b >= x and c >= x) {
            cout << ans << endl;
            return 0;
        }

        ans++;
        if(ans % 3 == 1) {
            a = b+c-1;
        } else if(ans % 3 == 2) {
            b = a+c-1;
        } else if (ans % 3 == 0) {
            c = a+b-1;
        }
    }

}