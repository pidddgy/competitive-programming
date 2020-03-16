// https://codeforces.com/contest/1315/problem/0

#include <bits/stdc++.h>
// #define cerr if(false) cerr
// #define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    #define int long long
    int t;
    cin >> t;

    while(t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        x++;
        y++;

        int c = a*(y-1);
        int d = b*(x-1);
        int e = (a-x)*b;
        int f = (b-y)*a;

        // watch(c)
        // watch(d)
        // watch(e)
        // watch(f)
        cout << max(c, max(d, max(e, f))) << endl;
        // cerr << endl;
    }
}